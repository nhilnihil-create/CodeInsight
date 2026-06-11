#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,x,y,i=0; cin>>n>>m;
    vector< pair<int,int> > adj[n+5];
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        adj[x].push_back(make_pair(y,i));
    }
    for(int i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end());
    vector<pair<int,int> > v[m+5];
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
             x=adj[i][j].second;y=adj[i][j].first;
             v[x].push_back(make_pair(i,j+1));
        }
    }
    for(int i=1;i<=m;i++){
        x=v[i][0].first;
        int c=0;
        while(x!=0){c++; x=x/10;}
        for(int k=0;k<6-c;k++)cout<<0; cout<<v[i][0].first;
        c=0;
        x=v[i][0].second;
        while(x!=0){c++; x=x/10;}
        for(int k=0;k<6-c;k++)cout<<0; cout<<v[i][0].second;
        cout<<endl;
    }

}

