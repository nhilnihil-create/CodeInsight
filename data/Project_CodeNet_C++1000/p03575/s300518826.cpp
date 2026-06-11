#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll N, M;
vector<bool> visited(50, false);
vector<vector<ll>> m(50, vector<ll>(50, 0));
vector<ll> A;
vector<ll> B;

void dfs(ll num)
{
//      cout << "DFS = " << num << endl;
        visited[num] = true;

        for (int i = 0; i < N; ++i) {

                if (m[num][i] == 1) {
                        if (visited[i] == true) continue;
                        else dfs(i);
                }
        }
}

int main()
{
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
                ll a, b; cin >> a >> b;
                A.push_back(a-1);
                B.push_back(b-1);
                m[a-1][b-1] = 1;
                m[b-1][a-1] = 1;
        }
        ll ans = 0;
        for (int i = 0; i < M; ++i) {

                for (int j = 0; j < N; ++j) visited[j] = false;

                m[A[i]][B[i]] = 0;
                m[B[i]][A[i]] = 0;

                dfs(0);

                m[A[i]][B[i]] = 1;
                m[B[i]][A[i]] = 1;

                for (int i = 0; i < N; ++i) {
                        if (visited[i] == false) {
                                ans++;
                                break;
                        }
                }

        }
        cout << ans << endl;


}
