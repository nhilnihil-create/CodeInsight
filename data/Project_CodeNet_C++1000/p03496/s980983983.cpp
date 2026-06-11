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
    vi v;
    v.pb(-1);
    int mi=1000001,ma=-1000001;
    int mat,mit;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        v.pb(k);
        if(k<mi){
            mi=k;
            mit=i;
        }
        if(k>ma){
            ma=k;
            mat=i;
        }
    }
    cout<<2*n-1<<endl;
    if(abs(ma)>=abs(mi)){
        for(int i=1;i<=n;i++){
            v[i]+=ma;
            cout<<mat<<' '<<i<<endl;
        }
        for(int i=1;i<=n-1;i++){
            cout<<i<<' '<<i+1<<endl;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            v[i]+=mi;
            cout<<mit<<' '<<i<<endl;
        }
        for(int i=n-1;i>=1;i--){
            cout<<i+1<<' '<<i<<endl;
        }
    }
    return 0;
}
