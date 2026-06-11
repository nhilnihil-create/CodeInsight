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
    int n;
    cin>>n;
    int c[n],s[n],f[n];
    for(int i=1;i<=n-1;i++){
        cin>>c[i]>>s[i]>>f[i];
    }
    for(int i=1;i<=n-1;i++){
        int ans=s[i]+c[i];
        for(int j=i+1;j<=n-1;j++){
            ans=max(ans,s[j]);
            while(ans%f[j]!=0){
                ans++;
            }
            ans+=c[j];
        }
        cout<<ans<<endl;
    }
    cout<<0<<endl;
    return 0;
}
