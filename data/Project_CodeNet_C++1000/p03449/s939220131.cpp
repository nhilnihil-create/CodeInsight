#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N; vector<vector<int>> A;
void input()
{
    cin >> N;
    A.resize(2); A[0].resize(N); A[1].resize(N);
    for (int i = 0; i < N; ++i) cin >> A[0][i];
    for (int i = 0; i < N; ++i) cin >> A[1][i];
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < N; ++i){
        int sum = 0;
        for (int j = 0; j <= i; ++j){
            sum += A[0][j];
        }
        for (int j = i; j < N; ++j){
            sum += A[1][j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}