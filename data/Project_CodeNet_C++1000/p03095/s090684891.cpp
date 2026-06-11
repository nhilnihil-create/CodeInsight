#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std; using ll=long long; const int m=1e9+7; using P=pair<int,int>;

int main() {
  int n; cin>>n;
  string s; cin>>s;
  ll a[26]; fill(a,a+26,0); for(int i=0;i<n;i++) a[s[i]-'a']++;

  ll an=1;
  for(int i=0;i<26;i++) {
    an = an * (a[i] + 1) % m; 
  }
  an = (an+m-1) % m;
  cout<<an<<endl;
}