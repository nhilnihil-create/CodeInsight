#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

string S;

const int N_MAX = 10e5;
int a, b;
int flg = 0;
string ans;
int tmpa, tmpb;
int tmpaval, tmpbval;
int amax = 0;
int buse = 0;
int cCount = 0;
int main()
{
    cin >> a >> b;
    if ((a * b) % 2 == 0)
    {
        ans = "Even";
    }
    else
    {
        ans = "Odd";
    }
    cout << ans;
    return 0;
}