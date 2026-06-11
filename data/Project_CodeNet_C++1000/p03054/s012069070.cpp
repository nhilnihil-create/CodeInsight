#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gpu_hash_map<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 100001;
int h, w, n, x, y;
bool state[mxN][2];
string tak;
string aok;
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>h>>w>>n>>x>>y>>tak>>aok;
    int x1 = 1;
    int y1 = 1;
    int x2 = h;
    int y2 = w;
    reverse(tak.begin(), tak.end());
    reverse(aok.begin(), aok.end());
    owo(i, 0, n) {
        if(aok[i]=='L')y2 = min(w, y2+1);
        if(aok[i]=='R')y1 = max(1, y1-1);
        if(aok[i]=='U')x2 = min(h, x2+1);
        if(aok[i]=='D')x1 = max(1, x1-1);
        if(tak[i]=='L')y1++;
        if(tak[i]=='R')y2--;
        if(tak[i]=='U')x1++;
        if(tak[i]=='D')x2--;
        if(x2<x1||y2<y1) {
            cout<<"NO\n";
            exit(0);
        }
    }
    //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<"\n";
    cout<<(x1<=x&&x2>=x&&y1<=y&&y2>=y ? "YES\n" : "NO\n");
    return 0;
}