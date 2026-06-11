#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 3)
    {
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }

    V res{2, 4, 3, 9};

    n -= 4;
    int n_ = n - (n % 2);

    for (int i = 8; i + 2 <= 30000; i += 6)
    {
        if (!n_)
            break;
        n_ -= 2;
        res.push_back(i);
        res.push_back(i + 2);
    }

    for (int i = 15; i + 6 <= 30000; i += 12)
    {
        if (!n_)
            break;
        n_ -= 2;
        res.push_back(i);
        res.push_back(i + 6);
    }

    for (int i = 6; i <= 30000; i += 6)
    {
        if (!n_)
            break;
        n_--;
        res.push_back(i);
    }

    if (n % 2)
        res.push_back(30000);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i == res.size() - 1 ? "\n" : " ");

    return 0;
}