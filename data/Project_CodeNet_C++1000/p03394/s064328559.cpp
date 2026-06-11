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
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

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
using std::fill;

using std::setprecision;
using std::fixed;

using std::min;
using std::max;

//#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
//typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

inline int nextInt()
{
    int x = 0;
    char c = getchar();
    int mi = (c == '-');
    if (c == '-') c = getchar();
    while ('0' <= c && c <= '9')
    {
        x = 10 * x + c - '0';
        c = getchar();
    }
    if (mi) return x * -1;
    return x;
}

int n, m;
vector<int> s;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 3)
    {
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }
    int nn = n;
    ll summ = 0;
    for (int i = 2; i < 30000; i++)
    {
        if (n > 2 && ((i % 2) == 0 || (i % 3) == 0))
        {
            s.push_back(i);
            summ += i;
            //cout << summ << endl;
            n--;
        }
    }
    for (int j = s[nn - 3] + 1; j <= 30000; j++)
    {
        for (int k = j + 1; k <= 30000; k++)
        {
            if (j % 2 == 0 || j % 3 == 0)
            {
                if (k % 2 == 0 || k % 3 == 0)
                {
                    if ((summ + j + k) % 6 == 0)
                    {
                        //cout << summ << " " << j + k << endl;
                        for (int i = 0; i < nn - 2; i++)
                        {
                            cout << s[i] << " ";
                        }
                        cout << j << " " << k;
                        return 0;
                    }
                }
            }
        }
    }
}
