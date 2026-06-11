#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

#define chmax(x,y) x=max(x,y)
int dp[10010]; // dp[i] : i本のマッチを丁度使う場合の最大桁数

int main()
{
    int N[10];
    N[1] = 2;
    N[2] = 5;
    N[3] = 5;
    N[4] = 4;
    N[5] = 5;
    N[6] = 6;
    N[7] = 3;
    N[8] = 7;
    N[9] = 6;

    int n, m;
    cin >> n >> m;
    vector<int> A(m);
    rep(i,m) cin >> A[i];
    sort(A.rbegin(), A.rend());

    rep(i,n) dp[i] = -1;
    dp[0] = 0;

    for (int i=1; i<=n; i++) {
        for (auto a : A) {
            int x = i - N[a];
            if (x < 0) continue;
            if (dp[x] == -1) continue;
            chmax(dp[i], dp[x] + 1);
        }
    }

    vector<int> Ans;
    int match = n;
    for (int i=dp[n]; i>=1; i--) {
        for (auto a : A) {
            if (match -N[a] < 0) continue;
            if (dp[match-N[a]] == i-1) {
                Ans.push_back(a);
                match -= N[a];
                break;
            }
        }
    }

    for (auto ans : Ans) {
        cout << ans;
    }
    cout << endl;

    return 0;
}