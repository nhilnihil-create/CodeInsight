#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n, m, k;
int a[100][100];
set < int > s[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m >> k;
        for(int i = 1; i <= k; i++){
                int x, y;
                cin >> x >> y;
                s[x].insert(y);
                //a[x][y] = 1;
        }
        //for(int i = 1; i <= n; i++, cout << "\n") for(int j = 1; j <= m; j++) cout << a[i][j];
        int res = 1, l = 1, r = 1;
        while(res < n){
                res += 1;
                auto p = s[res].lower_bound(l);
                if(p != s[res].end() && *p <= r){
                        res -= 1;
                        break;
                }
                if(s[res].find(r + 1) == s[res].end()){
                        r += 1;
                }
        }
        cout << res << "\n";
}
