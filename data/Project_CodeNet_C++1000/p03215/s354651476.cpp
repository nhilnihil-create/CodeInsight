#include<bits/stdc++.h>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  
  vector<long long> s(N + 1);
  s[0] = 0;
  for(int i = 0; i < N; i++) s[i + 1] = s[i] + a[i];
  
  queue<long long> q;
  for(int l = 0; l < N; l++){
    for(int r = l + 1; r <= N; r++){
      q.push(s[r] - s[l]);
    }
  }
  
  long long beauty = 0ll;
  for(int b = 63; b >= 0; b--){
    int bit_count = 0;
    for(int j = q.size(); j > 0; j--){
      long long qf = q.front();
      q.pop();
      if(qf & (1ll << b)) bit_count++;
      q.push(qf);
    }
    
    if(bit_count < K) continue;
    
    beauty += (1ll << b);
    for(int j = q.size(); j > 0; j--){
      long long qf = q.front();
      q.pop();
      if(qf & (1ll << b)) q.push(qf);
    }
  }
  
  cout << beauty << endl;
  
  return 0;
}