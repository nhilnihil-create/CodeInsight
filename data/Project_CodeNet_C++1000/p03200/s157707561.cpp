#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;
  ll n = s.size();
  
  ll ans = 0, res = 0;
  for(ll i=0; i<n; ++i){
    if(s[i]=='W'){
      ans += res;
    }
    else res++;
  }

  cout << ans;
  return 0;
}