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
    int N;
    cin >> N;
    vector<int> c(N), s(N), f(N);
    rep(i, N - 1)cin >> c[i] >> s[i] >> f[i];
    rep(i, N){
        ll ans = 0;
        for(int j = i; j < N - 1; j++){//jからj+1への時間を逐次足していく
            if(ans < s[j]) ans = s[j] + c[j];//１本目に乗れる
            else{
                if(ans % f[j] != 0){//ansに最も近いansに書き換え
                    ans += f[j] - (ans % f[j]);
                }
                ans += c[j];
            }
            // cout << "j: " << j << " ans: " << ans << endl;
        }
        cout << ans << endl;
    }
} 