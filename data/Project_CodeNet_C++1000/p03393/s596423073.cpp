#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  string s,out="";cin>>s;
  vector<bool> used(26,false);
  if(s.size()<26){
    out = s;
    for(int i=0;i<s.size();++i){
      int c = (int)(s[i]-'a');
      used[c] = true;
    }
    for(int j=0;j<used.size();++j){
      if(!used[j]){
        out += (char)(j+'a');
        break;
      }
    }
  } else {
    int sid =-1;
    int aid =-1;
    for(int j=0;j<s.size();++j){
      int cid = (int)(s[s.size()-1-j] - 'a');
      used[cid] = true;
      for(int i=cid+1;i<26;++i){
        if(used[i]){
          sid = s.size()-1-j;
          aid = i;
          break;
        }
      }
      if(sid>-1)break;
    }
    if(sid>-1){
      out += s.substr(0,sid);
      out += (char)(aid+'a');
    } else {
      out = "-1";
    }
  }
  cout << out << endl;
  return 0;
}
