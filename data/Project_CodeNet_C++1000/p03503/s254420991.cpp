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

string arr[1024];

void dobin(void){
    for(int i=0;i<1024;i++){
        int j=i;
        string s="";
        while(j>0){
            s+='0'+(j&1);
            j>>=1;
        }
        while(s.length()<10)
            s+="0";
        arr[i]=s;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    dobin();

    int f[n+1][11];
    for(int i=1;i<=n;i++){
        for(int k=1;k<=10;k++){
            cin>>f[i][k];
        }
    }

    int p[n+1][11];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10;j++){
            cin>>p[i][j];
        }
    }

    ll ans=-1000000000000000;
    for(int t=1;t<1024;t++){
        string s=arr[t];
        ll profit=0;
        for(int i=1;i<=n;i++){
            int count=0;
            for(int j=1;j<=10;j++){
                if(s[j-1]=='1' && f[i][j]==1){
                    count+=1;
                }
            }
            profit+=p[i][count];
        }
        if(profit>ans)
            ans=profit;
    }
    cout<<ans<<endl;
    return 0;
}
