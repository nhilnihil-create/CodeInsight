#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
int main(){
  string s;
  cin >> s;
  int n=s.size();
  ll a=0;
  ll ans=0;
  vector<int> k(n,0);
  rep(i,n-1){
    if(s[i]=='B'&&s[i+1]=='C'){
      k[i]=1;
      k[i+1]=2;
    }
  }
  rep(i,n){
    if(k[i]==2)continue;
    if(s[i]=='A'){
      a++;
      continue;
    }
    if(k[i]==1){
      ans+=a;
      continue;
    }
    else a=0;
  }
  cout << ans << endl;
}
