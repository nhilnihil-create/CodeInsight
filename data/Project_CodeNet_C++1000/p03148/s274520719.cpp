#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  vector<vector<int>> vec(N,vector<int>(2));
  for(int i=0; i<N; i++){
    for(int j=1; j>=0; j--){
      cin >> vec.at(i).at(j);
    }
  }
  sort(vec.rbegin(),vec.rend());
  map<int,bool> mp;
  priority_queue<int> PQ;
  int64_t ans = 0;
  
  for(int i=0; i<K; i++){
    int x = vec.at(i).at(0);
    int y = vec.at(i).at(1);
    if(mp.count(y)){
      PQ.push(-1*x);
    }
    else{
      mp[y] = true;
    }
    ans += x;
  }
  int64_t M = mp.size();
  
  vector<int> chance(0);
  for(int i=K; i<N; i++){
    int x = vec.at(i).at(0);
    int y = vec.at(i).at(1);
    if(mp.count(y)){
      continue;
    }
    else{
      chance.push_back(x);
      mp[y] = true;
    }
  }
  int64_t ans_x = ans;
  int64_t ans_c = ans + M*M;
  
  
  for(int i=0; i<chance.size(); i++){
    if(!PQ.size()){
      break;
    }
    int a = PQ.top();
    PQ.pop();
    M++;
    ans += chance.at(i) + a;
    ans_x = M*M + ans;
    ans_c = max(ans_c,ans_x);
  }
  cout << ans_c << endl;
}