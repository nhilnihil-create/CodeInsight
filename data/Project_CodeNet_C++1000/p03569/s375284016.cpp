#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;

int main(){
  string s; cin>>s; int n=s.size();
  string t;
  for(int i=0;i<n;i++) {
    if (s[i]!='x') t+=s[i];
  }
  int m=t.size();
  for(int i=0;i<m;i++) {
    if (t[i] != t[m-1-i]) {
      cout<<-1<<endl;
      return 0;
    }
  }
  int a[m+1]={};
  for(int i=0,j=0;i<n;i++) {
    if (s[i]=='x') a[j]++;
    else j++;
  }
  int an=0;
  for(int i=0;i<=m;i++) {
    an += max(0, a[i]-a[m-i]);
  }
  cout<<an<<endl;
}