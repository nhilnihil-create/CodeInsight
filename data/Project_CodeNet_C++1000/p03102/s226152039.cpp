#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 105

int n , m , c;
int b[MAXX];
int a[MAXX][MAXX];
int d[MAXX][MAXX];

int main()
{
    _FastIO;
    cin >> n >> m >> c;
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            d[i][j] = d[i][j - 1] + a[i][j] * b[j];
            if(j == m && ((d[i][m] + c) > 0))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
