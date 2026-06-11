#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  int k[q];
  rep(i,q){
    cin >> k[i];
  }
  ll Cdp[n],Mdp[n],CMdp[n];
  Cdp[0]=Mdp[0]=CMdp[0]=0;
  rep(i,n){
    if(i!=0){
      Cdp[i]=Cdp[i-1];
      Mdp[i]=Mdp[i-1];
      CMdp[i]=CMdp[i-1];
    }
    if(s[i]=='C'){
      Cdp[i]++;
      if(i!=0) CMdp[i]+=Mdp[i-1];
    }      
    else if(s[i]=='M'){
      Mdp[i]++;
    }
  }
  ll ans[q];
  rep(i,q) ans[i]=0;
  rep(i,n){
    if(s[i]=='D'){
      rep(j,q){
      int li=min(i+k[j]-1,n-1);
      ans[j]+=CMdp[li]-CMdp[i]-(Cdp[li]-Cdp[i])*Mdp[i];
      }
    }    
  }
  rep(i,q) cout << ans[i] << endl;
  return 0;
    

}
