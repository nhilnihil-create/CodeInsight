#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll ans=0;
  for(int i=1;i<n;i++){
    string t=s.substr(0,i),u=s.substr(i);
    vector<bool> ts(26,false),us(26,false);
    ll maxi=0;
    for(char c='a';c<='z';c++){
      rep(j,t.size()){
        if(t.at(j)==c){
          ts.at(c-'a')=true;
        }
      }
      rep(j,u.size()){
        if(u.at(j)==c){
          us.at(c-'a')=true;
        }
      }
    }
    rep(k,26){
      if(ts.at(k)==true &&us.at(k)==true){
        maxi++;
      }
    }
    ans=max(ans,maxi);
  }
  cout << ans;
}