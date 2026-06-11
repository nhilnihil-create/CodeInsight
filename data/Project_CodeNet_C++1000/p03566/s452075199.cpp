#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF ((int)(1e17))
#define EPS 1e6

signed main(){
  cout<<fixed<<setprecision(6);
  int N;
  int sum = 0;
  vector<int> t, v, maxs, maxs2;

  int  V = 0, bV = 0;
  double ans = 0;
  cin>>N;

  t.resize(N+10,0);
  v.resize(N+10,0);
  maxs.resize(N*210,0);
  
  maxs2.resize(N*210,0);
  
  for(int i = 0; i < N; i++){
    cin>>t[i];
  }
  for(int i = 0; i < N; i++){
    cin>>v[i];
    for(int j = 0; j < t[i]; j++){
      maxs[sum+j] = v[i];
    }
    for(int j = 1; j <= t[i]; j++){
      maxs2[sum+j] = v[i];
    }
    sum += t[i];
  }

  for(int i = sum+1; i >= 1; i--){
    maxs[i-1] = min(maxs[i-1], maxs[i]+1);
    
  }

  for(int i = 0, j = 0; i <= sum; i++){
    //cout<<i<<" "<<V<<" "<<maxs[i]<<" "<<maxs2[i]<<endl;
    if(maxs[i] == maxs[i+1]){
      if(V < maxs[i]){
	ans += V+0.5;
	V++;
      } else if(V == maxs[i]){
	ans += V;
	
      }
    } else if(maxs[i] < maxs[i+1]){
      if(maxs2[i+1] >= V+1){
	ans += V + 0.5;
	V++;
      } else {
	ans += V;
      }
    } else if(maxs[i] > maxs[i+1]){
      if(V == maxs[i+1]){
	ans += V + 0.25;
	
      } else if(V == maxs[i]){
	ans += V - 0.5;
	V--;
      } else  if(maxs[i+1] >= V+1){
	ans += V+ 0.5;
	V++;
      } 
    }
  }

  cout<<ans<<endl;
  
}
