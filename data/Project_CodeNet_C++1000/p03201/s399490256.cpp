#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

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
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};

int main(){
    ll n; cin >> n;
    multiset<ll> se;
    rep(i,n){
        ll a; cin >> a;
        se.insert(a);
    }
    ll ans = 0;
    multiset<ll> se2;
    for(ll bit=35; bit>=1; bit--){
        ll b = 1LL<<bit;
        se2 = se;
        for(auto i : se2){
            auto itr = se.find(i);
            if(itr == se.end()) continue;
            auto itr2 = se.find(b-i);
            if(itr==itr2) itr2++;
            if(itr2 != se.end() && *itr + *itr2 == b){
                se.erase(itr);
                se.erase(itr2);
                ans++;
            }
            if(se.size()==0 || se.size()==1) break;
        }
        if(se.size()==0 || se.size()==1) break;
    }
    cout << ans << endl;
}
