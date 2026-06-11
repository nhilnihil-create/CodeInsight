#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define reps(i, s, n) for(int i = (s); i < (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, s, n) for(int i = (n) - 1; i >= (s); i--)
#define INF ~(1 << 31)
#define INFL ~(1LL << 63)

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> h(n, vector<int>(3));
    rep(i, n){
        cin >> h[i][0] >> h[i][1] >> h[i][2];
    }
    vector<vector<int>> ans(n, vector<int>(3));
    ans[0][0] = h[0][0];
    ans[0][1] = h[0][1];
    ans[0][2] = h[0][2];
    reps(i, 1, n){
        ans[i][0] = max(ans.at(i-1).at(1), ans.at(i-1).at(2)) + h[i][0];
        ans[i][1] = max(ans.at(i-1).at(2), ans.at(i-1).at(0)) + h[i][1];
        ans[i][2] = max(ans.at(i-1).at(0), ans.at(i-1).at(1)) + h[i][2];
    }
    int ansmax = max(ans.at(n-1).at(0), ans.at(n-1).at(1));
    ansmax = max(ansmax, ans.at(n-1).at(2));
    cout << ansmax << endl;
}