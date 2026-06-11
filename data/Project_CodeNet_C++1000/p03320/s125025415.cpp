#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::setprecision;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::min;
using std::max;
using std::fill;
using std::max_element;
using std::min_element;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
//#define double long double

const long long MOD = 1e9 + 7;
const long long inf = 1e18;
const long long infsmart = 1e12;

vector<long long> ans;
vector<long long> nums;

double ds(ll x)
{
    ll y = 0;
    while (x > 0)
    {
        y += x % 10;
        x /= 10;
    }
    return y;
}

void Fgen(int stlen, int len, ll x)
{
    if (len == 0)
    {
        if (1)
        {
            nums.push_back(x);
        }
        return;
    }
    if (stlen - len <= 2)
    {
        for (int i = 0 + (stlen == len); i <= 9; i++)
        {
            x = 10 * x + i;
            Fgen(stlen, len - 1, x);
            x /= 10;
        }
    }
    else
    {
        x = 10 * x + 9;
        Fgen(stlen, len - 1, x);
        x /= 10;
    }
}

void gen(int len)
{
    nums.resize(0);
    Fgen(len, len, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(nums[i]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    for (int i = 1; i <= 9; i++)
    {
        ans.push_back(i);
    }
    for (int i = 2; i <= 16; i++)
    {
        gen(i);
    }
    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());
    vector<long long> rf(ans.size());
    double mn = ans[ans.size() - 1] / ds(ans[ans.size() - 1]);
    for (int i = ans.size() - 2; i >= 0; i--)
    {
        double x = ans[i] / ds(ans[i]);
        if (x <= mn)
        {
            mn = x;
            rf[i] = 1;
        }
        else
        {
            rf[i] = 0;
        }
    }
    for (int i = 0; k > 0; i++)
    {
        if (rf[i]) {
            cout << ans[i] << "\n";
            k--;
        }
    }
}
