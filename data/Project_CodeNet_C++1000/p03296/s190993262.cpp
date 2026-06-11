#include<bits/stdc++.h>
using namespace std;

int main(){
   int N,ans = 0;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  for(int i=0; i<N-1; i++){
    if(vec[i] == vec[i+1] && vec[i+1] == vec[i+2]){
      ans++;
      vec[i+1] = 10000-i;
    }
    else if(vec[i] == vec[i+1]){
      ans++;
      vec[i] = 10000-i;
    }
  }
  cout << ans << endl;
}

