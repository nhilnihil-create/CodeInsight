#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s.at(i);
  }
  string ans="Yes";
  rep(i,n-1){
    if(s.at(i).at(s.at(i).size()-1)!=s.at(i+1).at(0)){
      ans="No";
    }
  }
  sort(s.begin(),s.end());
  rep(i,n-1){
    if(s.at(i)==s.at(i+1)){
      ans="No";
    }
  }
  cout << ans;
}