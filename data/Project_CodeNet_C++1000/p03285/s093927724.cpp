#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  int ans=0;
  vector<int> s(390);
  for(int i=0;i<=25;i++){
    for(int j=0;j<=14;j++){
      if(N==4*i+7*j){
        ans=1;
        break;
      }
    }
  }
  
 
  
  if(ans==1){
    cout << "Yes" <<endl;
  }
  if(ans==0){
    cout << "No" <<endl;
  }
}
