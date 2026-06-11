#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

const ll mod = 1e9+7;

// void chmod(ll &M){
//     if(M >= mod) M %= mod;
//     else if(M < 0){
//         M += (abs(M)/mod + 1)*mod;
//         M %= mod;
//     }
// }

const ll MAX = 1e15;

ll S(ll N){
    ll res = 0;
    while(N != 0){
        res += N%10;
        N /= 10;
    }
    return res;
}

ll pow2(ll x, ll n){
    if(n == 0) return 1;

    ll res = pow2(x, n/2);
    if(n%2 == 0) return res*res;
    else return res*res*x;
}

// let f(N) be the integer n>=N that minimizes the value of n/S(n) (in case of tie, chose the smallest one)
ll f(ll n){
    ll res = n;
    double val = (double)n/S(n);

    ll d = 0;
    ll x = pow2(10, d+1)*(n/pow2(10, d+1) + 1)-1;
    while(x <= MAX){
        double tmp = (double)x/S(x);
        if(tmp < val){
            val = tmp;
            res = x;
        }
        ++d;
        x = pow2(10, d+1)*(n/pow2(10, d+1) + 1)-1;
        
    }

    return res;
}


int main(){
    int K; cin >> K;
    vector<ll> ans;

    ll n = 1;
    for(int i=0; i<K; ++i){
        ll add = f(n);
        ans.push_back(add);
        n = add+1;
    }

    for(auto e:ans) cout << e << endl;
}