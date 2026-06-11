#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N, K;
  cin >> N >> K;
  vector<vector<int64_t>> vec(N,vector<int64_t>(2));
  for(int i=0; i<N; i++){
    for(int j=0; j<2; j++){
      cin >> vec.at(i).at(j);
    }
  }
  sort(vec.begin(),vec.end());
  
  int64_t INF = 1e9 * 1e9 * 5;
  int64_t MINF = -1e9 * 1e9 * 5;
  
  int64_t ans = INF;
  
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      if(j - i + 1 < K){
        continue;
      }
      int64_t up = MINF;
      int64_t down = INF;
      vector<int64_t> length(0);
      for(int k=i; k<=j; k++){
        length.push_back(vec.at(k).at(1));
      }
      sort(length.begin(),length.end());
      int64_t ans_x = INF;
      for(int l=0; l+K-1<length.size(); l++){
        ans_x = min(ans_x, abs(length.at(l) - length.at(l+K-1)));
      } 
      ans_x *= (vec.at(j).at(0) - vec.at(i).at(0));
      ans = min(ans,ans_x);
    }
  }
  cout << ans << endl;
}