#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define pb push_back
#define MOD 1000000007
#define sz5 100005
#define sz6 1000005
#define UP upper_bound
#define LB lower_bound
#define F first
#define S second
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>
ll ans[1004][1004];

int main() {
    FAST

    ll n,m,la,lb;
    cin>>n>>m;
    string st[n];
    for(la=0;la<n;la++)
        cin>>st[la];

    memset(ans, 0, sizeof(ans));

    ans[1][1]=1;
    for(la=1;la<=n;la++){
        for(lb=1;lb<=m;lb++){
            if(la==1 && lb==1)
                continue;
            if(st[la-1][lb-1]=='#')
                ans[la][lb]=0;
            else
                ans[la][lb]=(ans[la-1][lb]+ans[la][lb-1])%MOD;
        }
    }

    // for(la=1;la<=n;la++){
    //     for(lb=1;lb<=m;lb++)
    //         cout<<ans[la][lb]<<' ';
    //     cout<<endl;
    // }

    cout<<ans[n][m]<<endl;

    return 0;
}