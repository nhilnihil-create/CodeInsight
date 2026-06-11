#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repm(i, a, n) for (ll i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define mod (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<vector<int>>
#define vllll vector<vector<ll>>
#define ALL(a) (a).begin(), (a).end()

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void print(bool f)
{
    cout << (f ? "Yes" : "No") << endl;
}

void Print(bool f)
{
    cout << (f ? "YES" : "NO") << endl;
}

int main(void)
{
    string s, t;
    cin >> s >> t;

    ll scnt = 1, tcnt = 1;
    map<char, int> mps, mpt;
    rep(i, 0, s.size())
    {
        if (mps[s[i]] == 0)
            mps[s[i]] = scnt++;
        s[i] = mps[s[i]] + '0';
        if (mpt[t[i]] == 0)
            mpt[t[i]] = tcnt++;
        t[i] = mpt[t[i]] + '0';
    }
    print(s == t);
}