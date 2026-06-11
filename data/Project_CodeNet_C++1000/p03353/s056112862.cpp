#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main(){
  string s;
  int k;
  cin>>s>>k;
  int sz=s.size();
  vector<vector<int>> v(26);
  rep(i,sz)
    v[s[i]-'a'].push_back(i);
  set<string> se;
  rep(i,26){
     rep(j,v[i].size()){
        int e=1;
        while(v[i][j]+e<=sz&&e<=k)
          se.insert(s.substr(v[i][j],e++)); 
     }
     if(se.size()>=k)
     break;
  }
  cout<<*next(se.begin(),k-1); 
  return 0;
}