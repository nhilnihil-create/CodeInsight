#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int sum=700;
  cin >> S;
  for(int i=0; i<3; i++){ 
    if(S[i]=='o') sum += 100;
  }
  cout << sum << endl;
  return 0;
}