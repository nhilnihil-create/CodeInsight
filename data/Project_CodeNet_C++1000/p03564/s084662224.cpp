#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  int ans=1;
  cin >> N >> M;
  int i=0;
  while(i<N){
   
    if(ans<M){
      ans *=2;
    }else{
      ans += M;
    }
    i++;
  }
  
  cout << ans << endl;
  return 0;
}