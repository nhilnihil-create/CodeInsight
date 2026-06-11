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
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    int ans=0;
    for(int i=0;i<m;i++){
        int visited[n+1];
        for(int j=0;j<=n;j++){
            visited[j]=0;
        }
        stack<int> s;
        vi v[n+1];
        for(int j=0;j<m;j++){
            if(i==j) continue;
            v[a[j]].pb(b[j]);
            v[b[j]].pb(a[j]);
        }
        s.push(1);
        visited[1]=1;
        while(!s.empty()){
            int u=s.top();
            s.pop();
            for(int j=0;j<v[u].size();j++){
                if(visited[v[u][j]]==0){
                    s.push(v[u][j]);
                    visited[v[u][j]]=1;
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(visited[j]==0){
                ans+=1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
