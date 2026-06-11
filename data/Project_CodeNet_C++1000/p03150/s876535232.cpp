#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
int main(){
  string s;
  cin >> s;
  
  ll n = s.size()-7;
  for(ll i=0;i<8;++i){
    string j = s.substr(0,i) + s.substr(i+n);
    //cout << j << "\n";
    if( j == "keyence" ){
	  puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}