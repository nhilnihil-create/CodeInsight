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
    //freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    vi v(3);
    scanf("%d %d %d %d", &v[0], &v[1], &v[2], &k);
    sort(all(v));
    rep(i, 1, k+1){
        v[2]*=2;
    }
    printf("%d",v[0]+v[1]+v[2]);
    return 0;
}