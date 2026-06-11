#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  int rAC[500000];
  rAC[0]=0;rAC[1]=0;
  rep(i,n){
    if(i==0)continue;
    if(s[i-1]=='A'&&s[i]=='C'){
      rAC[i+1]=rAC[i]+1;
    }else{
      rAC[i+1]=rAC[i];
    }
  }
  rep(i,q){
    int l,r;
    cin>>l>>r;
    cout<<rAC[r]-rAC[l]<<endl;
  }
}