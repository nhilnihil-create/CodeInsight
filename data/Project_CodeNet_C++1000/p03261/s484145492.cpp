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
typedef vector<string> vs;
int main()
{
    //freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string ts;
    cin >> n;
    set<string> S;
    int old_size = 0;
    string old_string = "";
    rep(i, 0, n)
    {
        cin >> ts;
        S.insert(ts);
        if (old_size == sz(S))
        {
            cout << "No" << endl;
            return 0;
        }
        old_size++;
        if (sz(old_string) > 0)
        {
            if (ts[0] != old_string[sz(old_string) - 1])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        old_string = ts;
    }
    cout << "Yes" << endl;
    // printf("%s", "Yes");
    return 0;
}