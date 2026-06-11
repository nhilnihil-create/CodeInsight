#include <iostream>
using namespace std;

int main(){
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int ans = 0;
  for(int i=0; i<=A; i++){
    for(int j=0; j<=B; j++){
      int res = X-500*i-100*j;
      if(0<=res && res<=50*C){
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}