#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  ll N,N_cp;cin>>N;N_cp=N;
  string S="";
  vector<ll> ans;
  while(N!=0){
    ll i=0,left=0,right=0;
    if(N>0){
      while(right<N){
        if(i%2==0) right += pow(-2,i);
        ++i;
      }
    }
    if(N<0){
      while(left>N){
        if(i%2!=0) left += pow(-2,i);
        ++i;
      }
    }
    N -= pow(-2,i-1);
    ans.push_back(i-1);
  }

  if(N_cp==0)cout << 0 << endl;
  else{
    sort(ans.begin(),ans.end(),greater<ll>());
    for(int i=ans[0];i>=0;i--){
      bool flag=false;
      rep(j,ans.size()){
        if(i==ans[j]) flag=true;
      }
      if(flag) cout<<1;
      else cout<<0;
    }
  }
  cout << endl;
}