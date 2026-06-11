#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
unordered_map<int,int> mp;
void dfs(int s){
    mp[s]=1;
    for(int j=0;j<(int)tree.at(s).size();j++){
        int g=tree.at(s).at(j);
        if(mp[g]==0){
            mp[g]=1;
            dfs(g);
        }
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    tree.resize(N,vector<int>(0));
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        tree.at(a-1).push_back(b-1);
        tree.at(b-1).push_back(a-1);
    }
    int sum=0;
    for(int i=0;i<N;i++){
        if(mp[i]==0){
            dfs(i);
            sum++;
        }
    }
    cout<<sum<<endl;
}