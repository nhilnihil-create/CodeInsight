#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    vector<int> up(N), down(N);
    for(int i = 0; i < 2; i++) for(int j = 0; j < N; j++) {
        cin >> A[i][j];
        if(i == 0) {
            if(j == 0) up[j] = A[i][j];
            else up[j] = up[j - 1] + A[i][j];
        }
        else {
            if(j == 0) down[j] = A[i][j];
            else down[j] = down[j - 1] + A[i][j];
        }
    }
    int ans = up[0] + down[N - 1];
    for(int i = 1; i < N; i++) {
        ans = max(ans, up[i] + down[N - 1] - down[i - 1]);
    }
    cout << ans << endl;
    return 0;
}