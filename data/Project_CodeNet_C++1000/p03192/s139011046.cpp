#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  int count = 0;
  rep(i,4){
    if(s[i] == '2') ++count;
  }
  cout << count << endl;
  return 0;
}
