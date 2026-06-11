#include<bits/stdc++.h>
using namespace std;
int find(int x,vector<int>&root){
    if(root[x]==x)return x;
    else return find(root[x],root);
}
int main(){
    int n,m;
    cin>>n>>m;
    int p[n];
    vector<int>root(n);
    vector<int>rank(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
        root[i]=i;
    }
    int x[m],y[m];
    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i];
        int X=find(x[i]-1,root),Y=find(y[i]-1,root);
        if(X==Y)continue;
        if(rank[X]<rank[Y])root[X]=Y;
        else{
            root[Y]=X;
            if(rank[X]==rank[Y])rank[X]++;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)if(find(i,root)==find(p[i],root))ans++;
    cout<<ans<<endl;
    return 0;
}