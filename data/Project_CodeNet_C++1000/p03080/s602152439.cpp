#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s;
  int r=0;
  cin >> N >> s;
  for(int i=0; i<N; i++){
    if(s[i]=='R') r++;
  }
  if(r>N-r){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}