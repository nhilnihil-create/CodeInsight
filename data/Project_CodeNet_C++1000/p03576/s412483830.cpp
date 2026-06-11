#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1000000007;
const long long inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    vi x(n),y(n);
    vi xarr,yarr;

    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        xarr.pb(x[i]);
        yarr.pb(y[i]);
    }
    sort(xarr.begin(),xarr.end());
    sort(yarr.begin(),yarr.end());
    ll ans=1LL*(xarr[n-1]-xarr[0])*(yarr[n-1]-yarr[0]);

    for(int xi=0;xi<n;xi++){
        for(int xj=xi+1;xj<n;xj++){
            for(int yi=0;yi<n;yi++){
                for(int yj=yi+1;yj<n;yj++){

                    int num=0;
                    ll lx=xarr[xi],rx=xarr[xj];
                    ll by=yarr[yi],uy=yarr[yj];

                    for(int i=0;i<n;i++){
                        if(lx<=x[i] && x[i]<=rx && by<=y[i] && uy>=y[i]){
                            num+=1;
                        }
                    }

                    if(num>=k){
                        ans=min(ans,1LL*(rx-lx)*(uy-by));
                    }

                }
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
