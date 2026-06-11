#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)
#define pow10(n) int(1e##n + n)

typedef long long LL;
typedef pair<int, int> P;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;

void solve()
{
    list<int> lst;
    int N;
    cin >> N;

    REP1 (i, N)
    {
        int b;
        cin >> b;
        lst.push_front(b);
    }
    vector<int> ans;
    while (lst.size())
    {
        int N = lst.size();
        int i = N;
        bool isok = false;
        for (auto itr = lst.begin(); itr != lst.end(); itr++)
        {
            if (*itr == i)
            {
                lst.erase(itr);
                isok = true;
                ans.push_back(i);
                break;
            }
            i--;
        }

        if (!isok)
        {
            std::cout << -1 << endl;
            return;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto n : ans)
    {
        std::cout << n << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
