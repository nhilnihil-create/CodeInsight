#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int x = 0;
  for(int i=0; i<S.size(); i++){
    if(S.at(i) == 'x'){
      x++;
    }
  }
  if(x >= 8){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
  }
}