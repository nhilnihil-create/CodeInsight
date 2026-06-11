#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int p[N];
int s[N];
int f[N];
long long d[N];
vector < int > v[N];
pair < long long, int > a[N];

int get(int x){ return f[x] == x ? x : f[x] = get(f[x]); }

void dfs(int x, int p, int dip = 0)
{
        d[1] += dip;
        s[x] = 1;
        for(int y: v[x]) if(y != p){
                dfs(y, x, dip + 1);
                s[x] += s[y];
        }
}

void trace(int x, int p)
{
        for(int y: v[x]) if(y != p){
                d[y] = d[x] + (n - s[y]) - s[y];
                trace(y, x);
        }
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi;
                a[i].se = i;
                s[i] = 1;
                f[i] = i;
        }
        sort(a + 1, a + n + 1);
        map < long long, int > id;
        for(int i = 1; i <= n; i++){
                id[a[i].fi] = i;
        }

        for(int i = n; i > 1; i--){
                long long dp = a[i].fi;
                dp = dp + s[i] - (n - s[i]);
                if(id.find(dp) == id.end() || dp > a[i].fi){
                        cout << -1 << "\n";
                        return 0;
                }
                p[i] = id[dp];
                s[p[i]] += s[i];

                int px = get(i), py = get(p[i]);
                if(px == py){
                        cout << -1 << "\n";
                        return 0;
                }
                f[px] = py;
        }
        if(s[1] != n){
                cout << -1 << "\n";
                return 0;
        }
        for(int i = 2; i <= n; i++){
                int x = a[i].se;
                int y = a[p[i]].se;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        trace(1, 1);
        for(int i = 1; i <= n; i++){
                if(d[a[i].se] != a[i].fi){
                        cout << -1 << "\n";
                        return 0;
                }
        }
        for(int i = 2; i <= n; i++){
                int x = a[i].se;
                int y = a[p[i]].se;
                cout << x << " " << y << "\n";
        }
}
