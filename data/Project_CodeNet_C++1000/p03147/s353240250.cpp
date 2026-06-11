#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vii = vector<vi>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
    ll n;
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];
    ll ans = 0;
    bool z = true;
    while (z){
        z = false;
        bool z1 = false;
        rep(i, n){
            if(h[i]==0&&z1){
                ans++;
                z1 = false;
            }
            else if(h[i]==0&&!z1)continue;
            else if(h[i]!=0&&i==n-1){
                h[i]--;
                z = true;
                ans++;
            }
            else{
                z = true;
                z1 = true;
                h[i]--;
            }
        }
    }
    print(ans);
}