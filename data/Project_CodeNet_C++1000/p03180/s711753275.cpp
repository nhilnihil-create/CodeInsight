#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+5;
const int MAXNN = 20;
const int INF = 1e9+7;
#define ll long long
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F first
#define S second
#define mp make_pair

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll MOD(ll a){
    return ((a%INF)+INF)%INF;
}

ll inv(ll a){
    return poww(a,INF-2,INF);
}

ll a[MAXNN][MAXNN],dp[(1<<MAXNN)],cost[(1<<MAXNN)];

int main()
{
    fast_io;
    //cout << fixed << setprecision(15);

    int n;cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<(1<<n);++i){
        for(int j=1;j<=n;++j){
            for(int f=j+1;f<=n;++f){
                if((i & (1<<(f-1))) && (i & (1<<(j-1)))){
                    cost[i] += a[j][f];
                }
            }
        }
    }

    dp[0] = 0;
    for(int i=0;i<(1<<n);++i){
        for(int prev = i;prev >0;prev = (prev - 1) & i){
            dp[i] = max(dp[i],dp[i ^ prev] + cost[prev]);
        }
    }
    cout << dp[(1<<n)-1];
}
