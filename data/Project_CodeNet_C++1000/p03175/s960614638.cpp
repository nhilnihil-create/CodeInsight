#include<iostream>
using namespace std;
#include<vector>
#define mod 1000000007

int n;
vector<int> graph[100006];
long long dp[100006][2];

void solution(int sv , int parent){
    
    long long white = 1;
    long long black = 1;
    for(int i=0 ; i<graph[sv].size() ; i++){
        if(graph[sv][i]!=parent){
            solution(graph[sv][i] , sv);
            white = (white*((dp[graph[sv][i]][1] + dp[graph[sv][i]][0])%mod))%mod;
            black = (black*dp[graph[sv][i]][0])%mod;
        }
    }
    dp[sv][0] = white;
    dp[sv][1] = black; 


}


int main(){
     
    cin>>n;
    for(int i=0 ; i<n-1 ; i++){
        int s , d;
        cin>>s>>d;
        graph[s].push_back(d);
        graph[d].push_back(s);
    } 
    solution(1 , 0);
    cout<<(dp[1][0]+dp[1][1])%mod<<endl;

}