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
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
    //freopen("A.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    vi v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(all(v));
    cout << v[2]*10+v[1]+v[0] << endl;
    return 0;
}