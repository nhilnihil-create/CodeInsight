#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S;
  if(S.size()==2){
    T=S;
  }
  else{
    reverse(S.begin(),S.end());
    T=S;
  }
  cout << T << endl;
}