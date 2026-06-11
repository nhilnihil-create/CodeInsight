// g++ -std=c++14

//Difficulty according to solve count during contest:
//A B C D H F E I G K L M N P S O Q R J U Z Y X T V W

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int n;
vector<vector<int> > child;
vector<vector<int> > dp;

void func(int node, int par){
  for(auto &x: child[node]){
    if(x != par)
      func(x, node);
  }
  dp[node][0] = 1;
  dp[node][1] = 1;
  for(auto &x: child[node]){
    if(x != par){
      dp[node][0] *= dp[x][1];
      dp[node][1] *= (dp[x][0] + dp[x][1]);
      dp[node][0] %= mod;
      dp[node][1] %= mod;
    }
  }
}


int32_t main(){
  cin >> n;
  child.resize(n + 1);
  dp.resize(n + 1, vector<int>(2, 0));
  for(int i = 0; i < n - 1; i++){
    int x, y;
    cin >> x >> y;
    child[x].push_back(y);
    child[y].push_back(x);
  }
  func(1, -1);
  cout << (dp[1][0] + dp[1][1]) % mod << endl;
}
