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
    vi a;
    for(int i=0;i<n;i++){
        ll p;
        cin>>p;
        a.pb(p);
    }
    sort(a.begin(),a.end());
    a.pb(-1);
    vi count;
    int c=1;
    int p=a[0];
    for(int i=1;i<=n;i++){
        if(a[i]==p){
            c+=1;
        }
        else{
            count.pb(c);
            c=1;
            p=a[i];
        }
    }
    sort(count.begin(),count.end());
    ll ans=0;
    if(count.size()>k){
        for(int i=0;i<count.size()-k;i++){
            ans+=count[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
