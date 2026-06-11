#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 100100100100100100;//10^17
const ll MOD = 1000000007;


ll combination(ll n, ll r){
    if(n < r) return 0;
    if(r == 0||r == n) return 1;
    else if(r == 1) return n;
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

bool checkKaibun(string str){
    string checkStr = str;
    reverse(checkStr.begin(), checkStr.end());
    if(str == checkStr) return true;
    else return false;
}

int keta(ll num){
    int digits = 0;
    while(num > 0){
        num /= 10;
        digits++;
    }
    return digits;
}


ll mpow(ll x, ll n){//繰り返し二乗法 計算量O(logN)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans * x % MOD;
        x = x * x % MOD;
        n  = n >> 1;
    }
    return ans;
}

int gcd(int a, int b){
    if(a % b == 0) return b;
    else return (gcd(b, a%b));
}



int main(){
    ll N, M;
    cin >> N >> M;
    if(N == 1 || M == 1){
        if(N == 1 && M == 1){
            cout << 1 << endl;
            return 0;
        }
        int t = max(N, M);
        cout << t - 2 << endl;
        return 0;
    }
    if(N > 2 && M > 2){
        cout << (N - 2) *  (M - 2) << endl;
        return 0;
    }
    cout << 0 << endl;
}