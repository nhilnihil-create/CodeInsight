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
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int count = A % 2 + B % 2 + C % 2;
    if (count == 0 || count == 3)
    {
        int m = max(max(A, B), C);
        cout << (m - A) / 2 + (m - B) / 2 + (m - C) / 2 << endl;
    }
    else if (count == 1)
    {
        A = A + 1 - A % 2;
        B = B + 1 - B % 2;
        C = C + 1 - C % 2;
        int m = max(max(A, B), C);
        cout << (m - A) / 2 + (m - B) / 2 + (m - C) / 2 + 1 << endl;
    }
    else
    {
        A += A % 2;
        B += B % 2;
        C += C % 2;
        int m = max(max(A, B), C);
        cout << (m - A) / 2 + (m - B) / 2 + (m - C) / 2 + 1 << endl;
    }
}