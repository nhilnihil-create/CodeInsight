#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> vertices;
vector<int> dp;

int longestPath(int root){
    if(dp[root] != -1) return dp[root];
    int max = 0;
    for(int vertex: vertices[root]){
        dp[vertex] = longestPath(vertex);
        if(dp[vertex] > max){
            max = dp[vertex];
        }
    }
    dp[root] = 1+max;
    //cout<<root<<"->"<<max<<endl;

    return dp[root];
}

int main(){
    int N,M;
    cin>>N>>M;
    int maximum = 0;

    vertices = vector<vector<int>>(N+1);
    dp = vector<int>(N+1,-1);
    for(int i = 0; i < M; i++){
        int from,to;
        cin>>from>>to;
        vertices[from].push_back(to);
    }
    for(int i = 1; i <= N; i++){
        if(dp[i] == -1){
            int res = longestPath(i);
            if(res > maximum){
                maximum = res;
            }
        }
    }
    //cout<<endl;
    cout<<maximum-1;
    // cout<<endl;

    // for(int i = 1; i <= N;i++){
    //     cout<<dp[i]<<" ";
    // }
}