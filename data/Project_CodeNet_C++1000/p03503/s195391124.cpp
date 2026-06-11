#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int N; vector<vector<int>> F,P;
void input()
{
    cin >> N;
    F.resize(N);
    P.resize(N);
    for (int i = 0; i < N; ++i){
        F[i].resize(10);
        P[i].resize(11);
    }
    for (int i = 0; i < N; ++i) for (int j = 0; j < 10; ++j) cin >> F[i][j];
    for (int i = 0; i < N; ++i) for (int j = 0; j < 11; ++j) cin >> P[i][j];
}

void solve()
{
    long long ans = -1e18;
    for (int op = 1; op < (1<<10); ++op){
        // cout << "open: " << op << endl;
        long long Psum = 0;
        for (int i = 0; i < N; ++i){
            int cnt = 0;
            for (int j = 0; j < 10; ++j){
                // int tmp = (op & (1<<j)) ? 1 : 0;
                // cout << tmp << " " << F[i][j] << " " << cnt << endl;
                if ((op & (1 << j)) && (F[i][j] == 1)) ++cnt;
            }
            // cout << endl;
            Psum += P[i][cnt];
        }
        // cout << Psum << endl << "---\n";
        ans = max(ans,Psum);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}