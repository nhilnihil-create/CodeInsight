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
    int A, B, K;
    cin >> A >> B >> K;
    if (B - A + 1 < 2 * K)
    {
        for (int i = A; i <= B; i++)
        {
            cout << i << endl;
        }
    }
    else
    {
        for (int i = A; i < A + K; i++)
        {
            cout << i << endl;
        }
        for (int i = B - K + 1; i <= B; i++)
        {
            cout << i << endl;
        }
    }
}