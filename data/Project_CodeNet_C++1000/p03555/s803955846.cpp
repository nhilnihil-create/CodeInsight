#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,T;
  cin >> S >> T;
  reverse(T.begin(),T.end());
  if(S==T){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}