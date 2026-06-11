#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std; typedef long long ll; const int INF=1e9; typedef pair<int,int> P;

int main() {
  string s; cin>>s;
  int n=s.size();
  if (n<26) {
    bool u[26]; fill(u,u+n,false);
    for(int i=0;i<n;i++) u[s[i]-'a']=true;
    for(int i=0;i<26;i++) {
      if (!u[i]) {
        cout<<s<<(char)('a'+i)<<endl;
        break;
      }
    }
  } else {
    int a[n], b[n];
    for(int i=0;i<n;i++) a[i]=s[i]-'a', b[i]=a[i];
    if (next_permutation(a,a+n)) {
      for(int i=0;i<n;i++) {
        cout<<(char)('a'+a[i]); if (a[i] != b[i]) break;
      } cout<<endl;
    } else {
      cout<<-1<<endl;
    }
  }
}