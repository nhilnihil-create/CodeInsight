#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  vector<int> v(N);
  for(int i=0; i<N; i++){
   cin >> v.at(i);
  }
  int ans = 0;
  ans = v.at(0)-v.at(1);
  if(ans < 0){
    ans *= -1;
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
    if(v.at(i) >= v.at(j)){
      if(v.at(i)-v.at(j) > ans){
        ans = v.at(i)-v.at(j);
      }
    }
    if(v.at(i) < v.at(j)){
      
   if(v.at(j)-v.at(i) > ans){
        ans = v.at(j)-v.at(i);
      }
    }
    }
  }
  cout << ans << endl;
    
	
}