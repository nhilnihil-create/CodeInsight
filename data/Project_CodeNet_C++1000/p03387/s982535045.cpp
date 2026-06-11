#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

int main()
{
    vector<int> v(3);
    int t = 0;
    REP(i,3){
        cin >> v[i];
    }
    int ans = 0;
    sort(ALL(v));
    IREP(i, 3)v[i] -= v[0];
    REP(i, 3)t += (v[i] % 2==0);
    REP(i, 3)
    {
        if (t == 1 && (v[i] % 2) == 1)
        {
            v[i]++;
            ans++;
        }
        if (t == 2 && (v[i] % 2) == 0)
        {
            v[i]++;
            ans++;
        }
    }
    ans += v[2] - v[1] + v[2] - v[0];
    ans /= 2;
    cout << ans << "\n";
    return 0;
}