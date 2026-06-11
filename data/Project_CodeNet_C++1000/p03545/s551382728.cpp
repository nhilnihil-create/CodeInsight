#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  string s;
  cin >> s;
  for(int bit=0;bit<(1<<3);bit++){
    int now = s[0]-'0';
    rep(i,3){
      if(bit&(1<<i)){
        now+=s[i+1]-'0';
      }
      else{
        now-=s[i+1]-'0';
      }
    }
    if(now == 7){
      vector<char>vec(3);
      rep(i,3){
        if(bit&(1<<i))vec[i]='+';
        else vec[i]='-';
      }
      cout << s[0]-'0';
      rep(i,3){
        cout << vec[i] << s[i+1]-'0';
      }
      cout << "=7" << endl;
      return 0;
    }
  }
  
  return 0;
}
