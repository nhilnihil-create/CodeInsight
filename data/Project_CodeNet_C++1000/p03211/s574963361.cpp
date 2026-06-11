#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  string S;
  cin>>S;
  int SS=S.size();
  int ans=1000;
  rep(i,SS-2){
    int check=(S[i]-'0')*100+(S[i+1]-'0')*10+(S[i+2]-'0');
    ans=min(ans,abs(753-check));
  }
  cout<<ans<<endl;
}