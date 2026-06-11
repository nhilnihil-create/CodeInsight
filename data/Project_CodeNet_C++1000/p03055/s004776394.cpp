#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v[max_n];
int n;

int max_d = -1, res = 0;

void find_far(int cur, int pr, int d) {
    if (d > max_d) {
        max_d = d;
        res = cur;
    }
    for (int to : v[cur]) {
        if (to == pr) continue;
        find_far(to, cur, d + 1);
    }
}

int find_d(int from) {
    max_d = -1;
    find_far(from, -1, 0);
    int v1 = res;
    max_d = -1;
    find_far(v1, -1, 0);
    int v2 = res;
    return max_d;
}

int dp[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    int d = find_d(0);
    dp[0] = 1;
    dp[1] = 0;
    for (int i = 2; i < max_n; ++i) {
        if (dp[i - 1] == 0 || dp[i - 2] == 0) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
        }
    }
    if (dp[d] == 1) {
        cout << "First";
    } else {
        cout << "Second";
    }
    return 0;
}


