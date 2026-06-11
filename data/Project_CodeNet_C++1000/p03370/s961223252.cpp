#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,X,ans=0;
  cin >> N >> X;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    X -= vec[i];
    ans++;
  }
  sort(vec.begin(),vec.end());
  if(X == 0){
    cout << ans << endl;
    return 0;
  }
  for(int i=0; X >= 0; X -= vec[0]){
    ans++;
  }
  cout << ans-1 << endl;
} 
