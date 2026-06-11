#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> T(5);
  int Min=9,last,Last,sum=0;
  
  for(int i=0;i<5;i++){
    cin >> T[i];
    if(T[i]%10 < Min && T[i]%10!=0){
      last = i;
      Min = T[i]%10;
    }
  }
  Last=T[last];
  T[last]=0;
  for(int i=0;i<5;i++){
    if(T[i]%10 == 0){
      sum +=T[i];
    }else{
      sum +=T[i] - T[i]%10 + 10;
    }
  }
  cout << sum+Last << endl;
  return 0;
}