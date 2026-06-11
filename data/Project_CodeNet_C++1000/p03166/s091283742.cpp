#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
unordered_map<int,list<int> > um;
int fun(int src,int *dist)
{
    if(dist[src]!=-1)return dist[src];
    int d=0;
    for(int i: um[src]){
        d=max(fun(i,dist)+1,d);
    }
    return dist[src]=d;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    int dist[n];
    for(int i=0; i<n; i++)dist[i]=-1;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        um[--x].push_back(--y);
    }
    for(int i=0; i<n; i++){
        if(dist[i]==-1){
            fun(i,dist);
        }
    }
    cout<<*max_element (dist,dist+n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
