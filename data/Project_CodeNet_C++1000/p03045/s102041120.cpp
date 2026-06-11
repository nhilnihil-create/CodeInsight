#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int x[m],y[m],z[m];
    vector<vector<int>>pas(n);
    for(int i=0;i<m;i++){
        cin>>x[i]>>y[i]>>z[i];
        pas[x[i]-1].push_back(y[i]-1);
        pas[y[i]-1].push_back(x[i]-1);
    }
    int check[n]={};
    int cost=0;
    for(int i=0;i<n;i++){
        if(check[i])continue;
        cost++;
        queue<int>q;
        q.push(i);
        check[i]=1;
        while(q.size()){
            int f=q.front();
            q.pop();
            for(int j=0;j<pas[f].size();j++){
                if(check[pas[f][j]]==0){
                    check[pas[f][j]]=1;
                    q.push(pas[f][j]);
                }
            }
        }
    }
    cout<<cost<<endl;
    return 0;
}