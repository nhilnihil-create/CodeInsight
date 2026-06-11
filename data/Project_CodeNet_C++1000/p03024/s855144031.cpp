#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string n;
  cin >> n;
  int k = n.length();
  int win=0;
  for(int i=0; i<k; i++){
    if(n[i]=='o'){
      win+=1;
    }
  }
  if((15-k+win)>=8){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}