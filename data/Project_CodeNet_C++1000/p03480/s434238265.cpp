#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const char sp = ' ';
const char cmm = ',';
const int MOD = 1000000007;

using ll = long long;

ll mod(ll a, ll b){return (a%b+b)%b;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void Judge(bool b){b?Yes():No();}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void JUDGE(bool b){b?YES():NO();}
ll powMod(ll b, ll e, ll m){ll r=1;while(e>0){if(e&1)r=(r%m)*(b%m)%m;b=(b%m)*(b%m)%m;e>>=1;}return r;}
double distance(ll x1, ll y1, ll x2, ll y2){return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}

template<typename T>
void ppp(T n){cout << n << endl;}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int ans = MOD;
    int n = s.size();
    for(int i = 1; i < n; ++i){
        if(s[i-1] != s[i]) ans = min(ans, max(i, n-i));
    }

    ppp(min(ans, n));



    return 0;
}
