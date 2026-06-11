#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int count =0,ans=0;
  
  for(int i=105;i<N+1;i++){
    if(i%2==0)continue;
    for(int j=1;j<=i;j++){
      if(i%j==0){
        count++;
      }
    }
    if(count==8)ans++;
    count=0;
  }
  cout << ans << endl;
}
