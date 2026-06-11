#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n;
  string count = "Three";
  cin >> n;
  vector<string> S(n);
  rep(i,n){
    cin >> S[i];
  }
  rep(i,n){
    if (S[i] == "Y"){
      count = "Four";
      break;
    }
  }
  cout << count << endl;
  return 0;
}
