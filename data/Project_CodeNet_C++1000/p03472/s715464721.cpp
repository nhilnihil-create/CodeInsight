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
    int n,h;
    cin>>n>>h;
    int a[n],b[n];
    int ma=0;
    int mat=-1;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        if(a[i]>ma){
            ma=a[i];
            mat=i;
        }
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        if(i==mat)  continue;
        if(b[i]>ma)
            v.pb(b[i]);
    }
    sort(v.rbegin(),v.rend());
    int ans=0;

    if(v.size()>0){
        for(int i=0;i<v.size();i++){
            if(b[mat]>v[i]){
                h-=b[mat];
                b[mat]=0;
                ans+=1;
            }
            if(h<=0) break;
            h-=v[i];
            ans+=1;
            if(h<=0) break;
        }
    }
    if(h>0){
        if(b[mat]>ma){
            ans+=1;
            h-=b[mat];
        }
        if(h>0){
            ans+=(h/ma);
            if(h%ma!=0)
                ans+=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
