#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int groups;
bool visited[MAXN];
vector<vector<int>> v1;
vector<pair<int,int>> edges;
int main(){
    int n;
    cin>>n;
    int val = n*(n+1)/2;
    for(int i=2;i<=n;i++){
        if(val%i == 0){
            groups = i;
            break;
        }
    }
    //cout<<groups<<endl;
    val/=groups;
   
    for(int i=n;i>=1;i--){
        if(visited[i]){
            continue;
        }
        int curr = val;
        curr-= i;
       
        vector<int> temp;
        temp.push_back(i);
        
        for(int j=i-1;j>=1;j--){
            if(visited[j]){
                continue;
            }
            
            if(j<=curr){
                curr-=j;
                visited[j] = true;
                temp.push_back(j);
            }
        }
        v1.push_back(temp);
    }
    for(int i=0;i<v1.size();i++){
        for(int j=i+1;j<v1.size();j++){
            for(int x=0;x<v1[i].size();x++){
                for(int y=0;y<v1[j].size();y++){
                   edges.push_back(make_pair(v1[i][x],v1[j][y]));
                }
            }
        }
    }
    cout<<edges.size()<<endl;
    for(auto x:edges){
        cout<<x.first<<" "<<x.second<<endl;
    }
}