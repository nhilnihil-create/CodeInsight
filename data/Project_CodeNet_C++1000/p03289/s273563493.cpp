#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  string s;
  cin>>s;
  
  int a=0;
  if(s[0]=='A') a++;
  int c=0;
  for(int i=2;i<s.size()-1;++i)
    if(s[i]=='C') c++;
  int b=0;
  rep(i,s.size()) if('A'<=s[i] && s[i]<='Z')
    b++;
  
  if(a==1 && c==1 && b==2) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
  return 0;
}
