#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  if(n == 3) reverse(s.begin(),s.end());
  cout << s << endl;
  return 0;
}
