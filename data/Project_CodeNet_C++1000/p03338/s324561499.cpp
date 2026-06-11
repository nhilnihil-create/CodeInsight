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
typedef vector<char> vc;
pii numbers_of_diffrent_letters_in_substring1(string s, int isplit)
{
    // string sub1 = s.substr(0, isplit);
    // string sub2 = s.substr(isplit, sz(s) - isplit);
    map<char, int> sub1m;
    map<char, int> sub2m;
    rep(i, 0, isplit)
    {
        sub1m[s[i]]++;
    }
    rep(i, isplit, sz(s))
    {
        sub2m[s[i]]++;
    }
    return make_pair<int, int>(sz(sub1m), sz(sub2m));
}
int intersection_num(string s, int isplit)
{
    // string sub1 = s.substr(0, isplit);
    // string sub2 = s.substr(isplit, sz(s) - isplit);
    set<char> S1, S2;
    vc vOut(26);
    rep(i, 0, isplit)
    {
        S1.insert(s[i]);
    }
    rep(i, isplit, sz(s))
    {
        S2.insert(s[i]);
    }
    auto it = set_intersection(all(S1), all(S2), vOut.begin());
    return it - vOut.begin();
}

int main()
{
    // freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char s[256];
    int n;
    scanf("%d %s", &n, &s);
    int mx = 0, ansi = -1;
    rep(i, 1, n - 1)
    {
        if (mx < intersection_num(s, i))
        {
            ansi = i;
            mx = max(mx, intersection_num(s, i));
        }
    }
    printf("%d",mx);
    return 0;
}