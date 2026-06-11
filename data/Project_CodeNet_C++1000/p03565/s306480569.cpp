#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  int res = INF;
  rep(i,int(s.size())-int(t.size())+1){
    int tmp = 0;
    rep(j,int(t.size())){
      if(s[i+j]=='?' || s[i+j]==t[j])tmp++;
    }
    if(tmp==int(t.size()))res = i;
  }
  if(res==INF)cout << "UNRESTORABLE\n";
  else{
    s.replace(res,int(t.size()),t);
    rep(i,int(s.size()))if(s[i]=='?')s[i] = 'a';
    cout << s << endl;
  }
  return 0;
}