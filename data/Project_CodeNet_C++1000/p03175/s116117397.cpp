#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<int>graph[MAX];

int mul(int a, int b)
{
    return (ll) a * b % MOD;
}

pair<int, int>dfs(int nod, int dad)
{
    int all_whites = 1;
    int sth_is_black = 0;

    for(int &x : graph[nod])
        if(x != dad)
        {
            pair<int, int>aux = dfs(x, nod);

            int memo_all_whites = all_whites;
            all_whites = mul(all_whites, aux.second);
            sth_is_black = (mul(memo_all_whites, aux.first) + mul(sth_is_black, aux.first + aux.second)) % MOD;
        }

    return {all_whites, (all_whites + sth_is_black) % MOD};
}
int main()
{
    int n;

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    pair<int, int>sol = dfs(1, - 1);

    cout << (sol.first + sol.second) % MOD;

    return 0;
}
