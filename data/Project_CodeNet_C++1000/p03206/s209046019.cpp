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
    int d;
    cin >> d;
    switch (d)
    {
    case 25:
        cout << "Christmas" << endl;
        break;
    case 24:
        cout << "Christmas Eve" << endl;
        break;
    case 23:
        cout << "Christmas Eve Eve" << endl;
        break;
    case 22:
        cout << "Christmas Eve Eve Eve" << endl;
        break;
    };
    return 0;
}