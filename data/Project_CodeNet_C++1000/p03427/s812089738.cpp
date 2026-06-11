#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    int N = s.size();
    int flag = 0;
    rep(1, i, N)
    {
        if (s.at(i) != '9')
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << (s.at(0) - '1') + 9 * (N - 1) << endl;
    }
    else
    {
        cout << (s.at(0) - '0') + 9 * (N - 1) << endl;
    }
}