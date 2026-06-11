#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<long long> vl;
typedef std::vector<std::vector<long long>> vvl;
#define out(x) cout<<x<<"\n";
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}
 
ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}
 
using namespace std;

using P = pair<int, int>;
using PP = pair<P, int>;
#define x first.first
#define y first.second
#define h second
void solve()
{
    int n;
    cin >> n;
    vector<PP> v(n);
    rep(i, n) cin >> v[i].x >> v[i].y >> v[i].h;
    int memo = 0;
    rep(cx, 101)
    {
        rep(cy,101){
            int cnt = 0;
            int val = -1;
            rep(i, n)
            {
                if(v[i].h==0){
                    ++cnt;
                    continue;
                }
                if(val==-1)val = v[i].h + abs(v[i].x - cx) + abs(v[i].y - cy);
                if(val<1)
                    break;
                if (v[i].h + abs(v[i].x - cx) + abs(v[i].y - cy) ==val)
                {
                    memo = i;
                    ++cnt;
                }
            }
            if(cnt==n){
                bool ng = false;
                rep(i, n)
                {
                    if(v[i].h==0){
                        if(val-abs(v[i].x-cx)-abs(v[i].y-cy)>0)
                            ng = true;
                    }
                }
                if(ng)
                    continue;
                cout << cx << " " << cy << " " << v[memo].h + abs(v[memo].x - cx) + abs(v[memo].y - cy);
                return;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}
