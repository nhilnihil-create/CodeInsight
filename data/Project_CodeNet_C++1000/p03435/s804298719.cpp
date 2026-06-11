#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
int main()
{
    //freopen("C.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dif;
    vii mat(3, vi(3));
    rep(i, 0, 3)
    {
        rep(j, 0, 3)
        {
            cin >> mat[i][j];
        }
    }
    rep(i, 1, 3)
    {
        dif = mat[i][0] - mat[i - 1][0];
        rep(j, 1, 3)
        {
            if (mat[i][j] - mat[i - 1][j] != dif)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    rep(j, 1, 3)
    {
        dif = mat[0][j] - mat[0][j-1];
        rep(i, 1, 3)
        {
            if (mat[i][j] - mat[i][j-1] != dif)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}