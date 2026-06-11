#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  string s;
  cin>>s;
  ll ans=0;
  int cnt_A=0;
  rep(i,s.size()){
    if(s[i]=='A') cnt_A++;
    else if(i!=s.size()-1 && s[i]=='B' && s[i+1]=='C'){
      ans+=cnt_A;
      i++;
    }
    else cnt_A=0;
  }
  cout<<ans<<endl;
}