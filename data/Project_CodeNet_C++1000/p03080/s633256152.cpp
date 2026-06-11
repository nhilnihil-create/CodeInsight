#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,count=0;
  string S;
  cin >> N >> S;
  for(int i=0;i<N;i++){
    if(S.at(i)=='R'){
      count++;
    }
    else{
      count--;
    }
  }
  if(count>0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
    
      