#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin >> n >> s;
  long ans = 1;
  vector<int>moji(26,0);
  for(int i=0;i<n;i++){
    moji[(int)(s[i]-'a')]++;
  }
  long const mod = 1e9+7;
  for(int i=0;i<26;i++){
    ans *= (moji[i]+1);
    ans %= mod;
  }
  ans += mod-1;
  ans %= mod;
  cout<<ans<<endl;
}
