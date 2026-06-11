#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const int INF = 1e9;
const int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n,vector<int>());
    int m = 0;
    if(n%2 == 0){
        rep(i,n){
            rep(j,i){
                if(i+j==n-1) continue;
                graph[i].push_back(j);
                ++ m;
            }
        }
    }else{
        rep(i,n){
            rep(j,i){
                if(i != n-1 && i+j == n-2) continue;
                graph[i].push_back(j);
                ++ m;
            }
        }
    }
    cout << m << endl;
    rep(i,n)rep(j,graph[i].size()){
        cout << i+1 << " " << graph[i][j]+1 << endl;
    }
    return 0;
}