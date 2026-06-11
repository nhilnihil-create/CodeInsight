#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
  int a=0,b=0,c=0;
  string s;
  cin>>s;
  rep(i,s.size()) {
    if(s[i]=='a')a++;
    if(s[i]=='b')b++;
    if(s[i]=='c')c++;
  }
  if(max(a,max(b,c))-min(a,min(b,c))<=1) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
