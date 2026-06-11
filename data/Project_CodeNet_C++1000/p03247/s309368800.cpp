// AtCoder Beginner Contest 111 - Problem D: Robot Arms (https://beta.atcoder.jp/contests/abc111/tasks/arc103_b)
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

#define REP(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define REPN(i, N) for (int (i) = 0; (i) < N; (i)++)
#define DEC(i, b, a) for (int (i) = (b); (i) >= (a); (i)--)
#define DECN(i, N) for (int (i) = N - 1; (i) >= 0; (i)--)

#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))
#define LOGM(msg) (cerr << (msg))
#define LOGV(vec, sep) { cerr << #vec << " ="; for (const auto& v : (vec)) cerr << " " << v; cerr << (sep); }
#define LOGA(arr, N, sep) { cerr << #arr << " ="; for (int i = 0; i < N; ++i) cerr << " " << (arr)[i]; cerr << (sep); }
#define LOGA2(arr, N, M, sep) { cerr << #arr << " =\n"; for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cerr << (arr)[i][j] << " "; cerr << endl; } cerr << (sep); }

ostream& operator<<(ostream& os, const ii& p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

const int MAX { 1010 };

ii ps[MAX];

int mod2(int a, int b)
{
    return (((a + b) % 2) + 2) % 2;
}

void solve(int N)
{
    // A paridade da soma das coordenadas deve ser a mesma da soma dos comprimentos
    ll x, y;
    tie(x, y) = ps[0];
    auto p = mod2(x, y);

    REPN(i, N)
    {
        tie(x, y) = ps[i];
 
        if (mod2(x, y) != p)
        {
            cout << -1 << endl;
            return;
        }
    }
    
    int m = 31;
    vector<ll> ds;

    for (int i = 0; i < m; ++i)
        ds.push_back(1LL << i);

    if (p == 0)
    {
        ++m;
        ds.push_back(1);
    }

    cout << m << endl;

    REPN(i, m)
        cout << ds[i] << (i + 1 == m ? "\n" : " ");

    if (p == 0)
    {
        --m;
        ds.pop_back();
    }

    REPN(i, N)
    {
        tie(x, y) = ps[i];

        if (p == 0)
            --x;

        string cmds = "";

        DECN(j, m)
        {
            auto d = ds[j];

            if (llabs(x) > llabs(y))
            {
                if (x > 0) 
                {
                    cmds += 'R';
                    x -= d;
                } else
                {
                    cmds += 'L';
                    x += d;
                }
            } else 
            {
                if (y > 0)
                {
                    cmds += 'U';
                    y -= d;
                } else 
                {
                    cmds += 'D';
                    y += d;
                }
            }         
        }

        reverse(cmds.begin(), cmds.end());

        if (p == 0)
            cmds += 'R';

        cout << cmds << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    REPN(i, N)
        cin >> ps[i].first >> ps[i].second;

    solve(N);

    return 0;
}
