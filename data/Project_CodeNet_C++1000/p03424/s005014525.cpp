#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N,count=0;
  cin >> N;
  
  for(int i=0; i<N; i++){
    char x;
    cin >> x;
    if(x=='Y'){
      count++;
    }
  }
  
  if(count==0){
    cout << "Three" << endl;
  }
  else{
    cout << "Four" << endl ;
  }
    
}
