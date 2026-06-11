#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9+7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
#define INT_MAX 1e9+7

int main(){
    ll n; cin >> n;
    vl d(n);
    vl cnt(13,0);
    rep(i,n){
        cin >> d[i];
        cnt[d[i]]++;
    }
    ll ans = inf;
    ll ch = 0;
    vvl v(2);
    rep(i,12){
        if(cnt[i]==0) continue;
        ans = min(ans, i);
        if(cnt[i]>=3){
            puts("0");
            return 0;
        }
        if(cnt[i]==2){
            v[0].push_back(i);
            v[1].push_back(i);
            ans = min(ans, min(i,12-i)*2);
        }else{
            v[ch].push_back(i);
            ch = 1 - ch;
        }
    }
    if(cnt[12]>=2){
        puts("0");
        return 0;
    }else if(cnt[12]==1){
        v[0].push_back(12);
        v[1].push_back(12);
    }
    rep(i,2){
        if(v[i].empty()) continue;
        rep(j,v[i].size()-1){
            ans = min(ans, v[i][j+1] - v[i][j]);
        }
    }
    cout << ans << endl;
}