#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t ans=1;
  int64_t o=1;
  for(int i=0;i<N;i++){
    int A;
    cin >> A;
    ans*=3;
    if(A%2==0){
      o*=2;
    }else{
      o*=1;
    }
  }
  ans-=o;
  cout << ans << endl;
  return 0;
}
