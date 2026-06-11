#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
#define MOD 1000000007
  
using ll = long long;
using Graph = vector<vector<pair<ll,ll>>>;

int main(){
  int H,W; cin>>H>>W;
  vector<vector<int>> A(H,vector<int> (W));
  rep(i,H)rep(j,W)cin>>A.at(i).at(j);
  queue<pair<pair<int,int>,pair<int,int>>> res;
  rep(i,H-1)rep(j,W){
    if(A.at(i).at(j)%2){
      A.at(i+1).at(j)++;
      res.push(make_pair(make_pair(i+1,j+1),make_pair(i+2,j+1)));
    }
  }
  rep(j,W-1){
    if(A.at(H-1).at(j)%2){
      A.at(H-1).at(j+1)++;
      res.push(make_pair(make_pair(H,j+1),make_pair(H,j+2)));
    }
  }
  cout<<res.size()<<endl;
  while(!res.empty()){
    int a = res.front().first.first;
    int b = res.front().first.second;
    int c = res.front().second.first;
    int d = res.front().second.second;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    res.pop();    
  }
}