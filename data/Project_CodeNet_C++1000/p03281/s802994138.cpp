#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int ans =0;
  int myans =0;
  for(int i=3;i<=N;i++){
//    if( i % 2 !=0){
      for(int j=1;j<=N;j++){
        if (i%j ==0){
 //         cout << i << " " << j << " " << i%j << endl;
          myans++;
        }
      }
      if(myans == 8 && i % 2 !=0){
        ans++;
//        cout << i << endl;
      }
      myans = 0;
//    }
  }
  cout << ans << endl;
  
  return 0;
}