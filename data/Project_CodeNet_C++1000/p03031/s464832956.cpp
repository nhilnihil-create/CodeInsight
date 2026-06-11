#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e];

//beginner 1999 129
/// count : 3
int n, m;
ll p[e], x[e];
vector<ll>adj[e];
ll ans = 0;

void dq(int pos)
{
    if(pos == n+1){
        for(int i=1; i<=m; i++){
            ll dem = 0;
            for(auto j : adj[i]){
                if(x[j] == 1){
                    dem ++;
                }
            }
            if(dem%2 != p[i]%2){
                return ;
            }
        }
        ans ++;
        return ;
    }
    else{
        for(int i=0; i<2; i++){
            x[pos] = i;
            dq(pos+1);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        for(; x>0;x--){
            int bulbs;
            cin >> bulbs;
            adj[i].pb(bulbs);
        }
    }
    for(int i=1; i<=m; i++) cin >> p[i];
    dq(1);
    cout << ans;
}
