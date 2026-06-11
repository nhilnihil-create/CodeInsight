#include<bits/stdc++.h>
using namespace std;


int main(){
  int N, K;
  cin >> N >> K;
  vector<long long> V(N);
  
  for(int i=0; i<N; i++) cin >> V[i];
  
  int ans=0;
  
  for(int i=0; i<=K; i++){
    for(int j=0; j<=K-i; j++){
      if(i+j>N) continue;
      vector<long long> S;
      int res=0;
      
      for(int k=0; k<i; k++){
        res += V[k];
        S.push_back(V[k]);
      }
      for(int l=0; l<j; l++){
        res += V[N-l-1];
        S.push_back(V[N-l-1]);
      }
      
      sort(S.begin(), S.end());
          
      for(int k=0; k<(K-i-j); k++){
        if(k>=S.size()) break;
        if(S[k]>0) break;
        res -= S[k];
      }
     
      
      ans = max(ans, res);
    
    }
  }
  
  cout << ans << endl;
  
  return 0;

}