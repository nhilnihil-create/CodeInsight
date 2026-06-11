#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = INT_MAX;
const ll LLINF = INT64_MAX;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

const string SINF = "-";
int match[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void chmax(string &a, string b)
{
    if (a == SINF)
    {
        a = b;
    }
    else if (a.size() < b.size())
    {
        a = b;
    }
    else if (a.size() == b.size())
    {
        if (a < b)
        {
            a = b;
        }
    }
}

string dp[11000];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 11000; i++)
    {
        dp[i] = SINF;
    }
    dp[0] = "";
    for (int i = 0; i <= n; i++)
    {
        if (dp[i] == SINF)
        {
            continue;
        }
        for (auto num : a)
        {
            chmax(dp[i + match[num]], dp[i] + (char)('0' + num));
        }
    }
    cout << dp[n] << endl;
}