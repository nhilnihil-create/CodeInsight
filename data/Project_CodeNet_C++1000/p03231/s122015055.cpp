#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>
#include <iostream>

ll ans;
int N,M;
string S, T;

ll GCD(ll a, ll b){
    if(b==0) return a;

    return GCD(b, a % b);
}

ll LCM(ll a, ll b){
    ll ans;

    if(a > b) ans = (a / GCD(a, b)) * b;
    else ans = (b / GCD(a, b)) * a;

    return ans;
}


void solve(){
    ll tmp = LCM(N, M);
    bool flag = true;

    ll n = tmp / N;
    ll m = tmp / M;

    rep(i, GCD(N, M)){
        // cout << S[d2*i] << " vs " << T[d1*i] << endl;
        if(S[m*i] != T[n*i]){
            flag = false;
            break;
        }
    }
    
    if(flag)    
        cout << tmp << endl;
    else
        cout << -1 << endl;
    }

int main(){
    cin >> N >> M >> S >> T;

    solve();
}
