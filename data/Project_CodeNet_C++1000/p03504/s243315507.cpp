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

int ansarr[100001];
int arr[31][100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int s,t,c;
        cin>>s>>t>>c;
        arr[c][s]+=1;
        arr[c][t]-=1;
    }
    int ans=0;
    int count=0;

    for(int i=1;i<=k;i++){
        for(int j=0;j<=100000;j++){
            if(arr[i][j]==1){
                ansarr[j-1]+=1;
            }
            else if(arr[i][j]==-1){
                ansarr[j]-=1;
            }
        }
    }

    for(int i=0;i<=100000;i++){
        count+=ansarr[i];
        if(count>ans)
            ans=count;
    }
    cout<<ans<<endl;
    return 0;
}
