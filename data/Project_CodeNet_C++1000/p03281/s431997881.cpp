#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans =0;
  for(int i=1;i<=N;i++){
    int keta=0;
    for(int j=1;j<=i;j++){
      if((i%2)==1 & (i%j)==0){
        ++keta;
      }
    }
    if(keta == 8){
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
