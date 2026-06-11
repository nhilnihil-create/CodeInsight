#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s,t;
  cin >> s >> t;
  string ans="No";
  rep(i,s.size()){
    string u=s.substr(0,s.size()-1);
    char c=s.at(s.size()-1);
    s=c+u;
    if(s==t){
      ans="Yes";
    }
  }
  cout << ans;
}