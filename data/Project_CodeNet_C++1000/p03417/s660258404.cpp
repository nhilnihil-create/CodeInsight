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
    ll n,m;
    cin>>n>>m;
    if(n>=3 && m>=3)
        cout<<(n-2)*(m-2)<<endl;
    else if(n==2 || m==2)
        cout<<0<<endl;
    else if(n==1 && m==1)
        cout<<1<<endl;
    else if(n==1)
        cout<<m-2<<endl;
    else if(m==1)
        cout<<n-2<<endl;
    return 0;
}
