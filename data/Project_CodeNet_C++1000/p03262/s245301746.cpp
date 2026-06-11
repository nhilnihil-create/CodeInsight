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
typedef vector<ll> vl;
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main( ) {
    //freopen("C.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin >> n >> x;
    vl v(n);
    rep(i, 0, n){
        cin >> v[i];
        v[i]=abs(x-v[i]);
    }
    rep(i, 0, n-1){
        v[i+1]=gcd(v[i],v[i+1]);
    }
    cout << v[n-1] << endl;
    return 0;
}