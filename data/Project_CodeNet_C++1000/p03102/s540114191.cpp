#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n, m, c;
    cin >> n >> m >> c;
    int b[m], a[n][m];
    for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cur = c;
        for(int j = 0; j < m; j++)
            cur += a[i][j] * b[j];
        if(cur > 0) ans++;
    }
    cout << ans;
    return 0;
}
