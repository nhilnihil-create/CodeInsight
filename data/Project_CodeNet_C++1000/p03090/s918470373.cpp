#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<vector<bool>> connect(N, vector<bool>(N, true));
    rep(i, N)connect[i][i] = false;
    N -= N % 2;
    rep(i, N)connect[i][N - 1 - i] = false;

    int cnt = 0;
    for (auto row : connect)for (auto col : row)if (col)cnt++;
    cout << cnt / 2 << endl;

    const int M = connect.size();
    rep(i, M)rep(j, M)if (i < j&&connect[i][j])cout << i + 1 << " " << j + 1 << endl;
    cout << endl;
    return 0;
}
