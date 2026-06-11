#include<bits/stdc++.h>
using namespace std;
long long int MOD = 1e9+7;
int main(){
    int n,m;
    char x;
    cin>>n>>m;
    long long int adj[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            if(x=='.') adj[i][j]=0;
            else adj[i][j]=-1;
        }
    }
    if(adj[n-1][m-1]==0){
    adj[n-1][m-1]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(adj[i][j]==-1) adj[i][j]=0;
            else{
                if(i+1<n) adj[i][j] = adj[i+1][j];
                if(j+1<m) adj[i][j] += adj[i][j+1];
            }
            adj[i][j] = adj[i][j]%MOD;
            //cout<<adj[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<adj[0][0]%MOD;
    }
    else cout<<"0";
}