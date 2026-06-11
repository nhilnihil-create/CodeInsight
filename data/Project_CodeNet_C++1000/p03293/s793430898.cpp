#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;

int main(){
  string s,t; cin>>s>>t;
  bool ans = false;
  rep(i, s.size()){
    if (s==t){
      cout << "Yes" << endl;
      return 0;
    }
    s = s.back() + s.substr(0, s.size()-1);
  }
  cout << "No" << endl;
  return 0;
}