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
    vi a,b,c;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a.pb(k);
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        b.pb(k);
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        c.pb(k);
    }
    c.pb(-1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll ans[2][n+1];
    for(int i=0;i<=n;i++){
        ans[1][i]=0;
    }
    int index=n-1;      // index for b
    int i=0;            // i for c
    while(index>=0 && i<=n+1){
        if(c[n-i]<=b[index]){
            ans[1][index]=ans[1][index+1]+i;
            index-=1;
        }
        else{
            i+=1;
        }
    }
    index=0;
    ll count=0;
    int ca=0;
    for(int i=0;i<n;i++){
        for(int j=index;j<n;j++){
            if(b[j]>a[i]){
                count+=ans[1][j];
                index=j;
                break;
            }
            else{
                if(j==n-1){
                    ca=1;
                }
            }
        }
        if(ca==1){
            break;
        }
    }
    cout<<count<<endl;
    return 0;
}
