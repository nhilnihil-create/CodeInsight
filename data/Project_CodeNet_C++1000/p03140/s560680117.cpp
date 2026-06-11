#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

bool from1[2505];
bool fromN[2505];
bool ok[2505];
vector<vl> G(2505);
vector<vl> rG(2505);



int main(){
    ll n; cin >> n;
    string a,b,c; cin >> a >> b >> c;
    ll ans = 0;
    rep(i,n){
        if(a[i] != b[i] && b[i]!=c[i] && a[i]!=c[i]) ans+=2;
        else if(a[i] == b[i] && b[i] == c[i]) ans = ans;
        else ans++;
    }
    cout << ans << endl;
}
