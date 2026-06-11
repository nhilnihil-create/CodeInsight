#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N;
  cin >> N;
  
  int flag = 0;
  for(int i = 0; ;i++){
    if(4*i > N){
      break;
    }//if
    
    for(int j = 0; ; j++){
      int sum = 4*i + 7*j;
      if( sum == N ){
        flag = 1;
        break;
      }else if(sum > N){
        break;
      }
    }//for
    if(flag == 1){
      break;
    }
  }//for
  
  if(flag == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}