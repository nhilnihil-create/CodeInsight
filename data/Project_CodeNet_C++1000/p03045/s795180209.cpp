#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> Graph(N);
  for(int i=0;i<M;i++){
    int X,Y,Z;
    cin >> X >> Y >> Z;
    X--;
    Y--;
    Graph[X].push_back(Y);
    Graph[Y].push_back(X);
  }
  vector<bool> seen(N,false);
  stack<int> stack;
  vector<bool> complete(N,true);
  int ans=0;
  for(int j=0;j<N;j++){
    if(seen[j]==true){
      continue;
    }
    stack.push(j);
    while(!stack.empty()){
      int state=stack.top();
      seen[state]=true;
      stack.pop();
      for(int i:Graph[state]){
        if(seen[i]==true){
          continue;
        }
        seen[i]=true;
        stack.push(i);
      }
    }
    ans++;
  }
  cout << ans << endl;
}