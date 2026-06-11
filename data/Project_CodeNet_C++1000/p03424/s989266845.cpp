#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string Y,x;
  cin >> N;
  bool a =false;
  
	for(int i=0;i<N;i++){
      cin>>x;
      if(x=="Y")
      a =true;
    }
  if(a){
    cout<<"Four";
  }
      else{
        cout<<"Three";
  }
  
  
  
  
}
