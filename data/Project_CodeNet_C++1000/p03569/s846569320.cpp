#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  string s;cin >>s;
  string swox="";
  for(int i=0;i<s.size();++i)if(s[i]!='x')swox += s[i];
  bool kaibun = true;
  for(int i=0;i<swox.size();++i){
    if(swox[i]!=swox[swox.size()-1-i]){
      kaibun = false;
      break;
    }
  }
  if(kaibun){
    vector<int> v(swox.size()+1);
    int cnt = 0;
    int id =0;
    for(int i=0;i<s.size();++i){
      if(s[i]=='x'){
        ++cnt;
      } else {
        v[id] = cnt;
        cnt = 0;
        ++id;
      }
    }
    v[id] = cnt;
    int out = 0;
    for(int j=0;j<v.size()/2;++j){
      out += abs(v[j]-v[v.size()-1-j]);
    }
    cout << out << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
