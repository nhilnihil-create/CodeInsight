#include <bits/stdc++.h>
using namespace std;

int main() {
  long k;
  string s,ans;
  set<string> a;
  cin >> s >> k;
  for(long i=0;i<s.size();i++) {
    string aaa="";
    for(long j=0;j<k;j++) {
      if(i+j==s.size()) break;
      aaa=aaa+s[i+j];
      a.insert(aaa);
      if(a.size()<=k) continue;
      auto itr=a.end();
      itr--;
      a.erase(itr);
    }
  }
  auto itr=a.end();
  itr--;
  cout << *itr << endl;
}