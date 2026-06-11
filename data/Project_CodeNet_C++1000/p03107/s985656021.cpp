#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  int cnt_0=0,cnt_1=0;
  rep(i,s.size()){
    if(s[i]=='0')
    cnt_0++;
    else 
    cnt_1++;
  }
  int ans=s.size()-abs(cnt_0-cnt_1);
  cout<<ans<<endl;
}