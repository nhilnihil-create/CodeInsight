#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    //freopen("C.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m,ans=0,c=0,a,b;
    cin >> n >> m;
    multimap<ll, ll> mm;
    rep(i, 0, n){
        cin >> a >> b;
        mm.insert({a,b});
    }
    trav(it, mm){
        if(c==m){
            break;
        }
        else if(m<c+it.second){
            ans += it.first*(m-c);
            break;
        }
        c += it.second;
        ans += it.first*it.second;
    }
    cout << ans << endl;
    return 0;
}