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
    ll m=0,a=0,r=0,c=0,h=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s[0]=='M')
            m+=1;
        else if(s[0]=='A')
            a+=1;
        else if(s[0]=='R')
            r+=1;
        else if(s[0]=='C')
            c+=1;
        else if(s[0]=='H')
            h+=1;
    }
    ll ans=0;
    ans+=m*a*r;
    ans+=m*a*c;
    ans+=m*a*h;
    ans+=m*r*c;
    ans+=m*r*h;
    ans+=m*c*h;
    ans+=a*r*c;
    ans+=a*r*h;
    ans+=a*c*h;
    ans+=r*c*h;
    cout<<ans<<endl;
    return 0;
}
