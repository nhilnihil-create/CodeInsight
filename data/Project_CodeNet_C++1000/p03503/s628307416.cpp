#include <iostream>

using namespace std;
int main(){
  int n;cin>>n;
  int A[n][10];
  for(int i = 0; n > i; i++){
    for(int j = 0; 10 > j; j++){
      cin>>A[i][j];
    }
  }
  int B[n][11];
  for(int i = 0; n > i; i++){
    for(int j = 0; 10 >= j; j++){
      cin>>B[i][j];
    }
  }
  long long ans = -1000000000000;
  for(int bit = 1; (1<<10) > bit; bit++){
    long long tmp = 0;
    for(int i = 0; n > i; i++){
      long long nw = 0;
      for(int j = 0; 10 > j; j++){
        if(bit & (1<<j)){
          if(A[i][j]){
            nw++;
          }
        }
      }
      tmp += B[i][nw];
    }
    
    ans = max(ans,tmp);
  }
  cout << ans << endl;
}
