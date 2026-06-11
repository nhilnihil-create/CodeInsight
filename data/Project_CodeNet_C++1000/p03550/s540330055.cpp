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
    int n,z,w;
    cin>>n>>z>>w;
    vi v;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v.pb(k);
    }
    if(n==1){
        cout<<abs(v[0]-w)<<endl;
    }
    else{
        cout<<max(abs(v[n-1]-v[n-2]),abs(v[n-1]-w));
    }
    return 0;
}
