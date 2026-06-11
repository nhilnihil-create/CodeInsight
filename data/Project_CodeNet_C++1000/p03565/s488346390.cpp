#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
  string s,sp;
  cin >>s>>sp;
  for(int i=s.size();i>=0;i--){
    bool ok =true;
    rep(j,sp.size()){
      if(s[i+j]!=sp[j]&&s[i+j] !='?'){
        ok=false;
      }
    }
    if(ok){
      string ans ="";
      int count=0;
      for(int j=i;j<sp.size()+i;j++){
        s[j]=sp[count];
        count++;
      }
      rep(j,s.size()){
        if(s[j]=='?'){
          ans+="a";
        }else{
          ans+=s[j];
        }
      }
      cout << ans <<endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" <<endl;
}