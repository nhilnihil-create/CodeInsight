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
    int k;
    cin>>k;
    int visited[k+1];
    int distance[k+1];
    for(int i=0;i<k;i++){
        visited[i]=0;
        distance[i]=0;
    }
    vector<ii> arr[k+1];
    for(int i=0;i<k;i++){
        arr[i].pb(mp(1,(i+1)%k));
        arr[i].pb(mp(0,(i*10)%k));
    }

    deque<int> q;
    visited[1]=1;
    distance[1]=1;
    q.push_front(1);

    while(!q.empty()){
        int v=q.front();
        q.pop_front();
        visited[v]=1;
        for(int i=0;i<arr[v].size();i++){
            int node=arr[v][i].se;
            int d=arr[v][i].fi;
            if(visited[node]==0){
                if(d==0){
                    distance[node]=distance[v];
                    q.push_front(node);
                }
                else{
                    distance[node]=distance[v]+1;
                    q.push_back(node);
                }
            }
        }
    }
    cout<<distance[0]<<endl;
    return 0;
}
