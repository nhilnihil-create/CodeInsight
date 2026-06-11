#include "bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, n, k) for (int i = n; i < k; i++)
#define P(p) cout << (p) << endl;
#define sP(p) cout << setprecision(15) << fixed << p << endl;
#define vi vector<int>
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        P(v[i]);
#define printt(a, b) cout << a << " " << b << endl;
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int MOD = 1e9 + 7;

int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int maxi = -1;
    rep(i, n)
    {
        map<char, int> m1, m2;
        REP(j, 0, i)
        {
            m1[s[j]]++;
        }
        REP(j, i, n)
        {
            m2[s[j]]++;
        }
        int count = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (m1[c] != 0 && m2[c] != 0)
            {
                count++;
            }
        }
        maxi = max(maxi, count);
    }
    P(maxi);
}

int main()
{
    solve();
    return 0;
}