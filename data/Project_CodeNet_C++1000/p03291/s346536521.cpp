#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
int main(){
  string S;cin>>S;long N=S.length();
  vector<long>p(N+1);long x=1;for(long i=0;i<N;i++){p[i]=x;x=x*3%MOD;}
  vector<long>Al(N),Bl(N),Cl(N),Dl(N),Ar(N),Br(N),Cr(N),Dr(N);
  for(long i=0;i<N;i++){
    Al[i]=(i>0?Al[i-1]:0);Bl[i]=(i>0?Bl[i-1]:0);
    Cl[i]=(i>0?Cl[i-1]:0);Dl[i]=(i>0?Dl[i-1]:0);
    if(S[i]=='A')Al[i]++;
    if(S[i]=='B')Bl[i]++;
    if(S[i]=='C')Cl[i]++;
    if(S[i]=='?')Dl[i]++;
  }
  for(long i=N-1;i>=0;i--){
    Ar[i]=(i<N-1?Ar[i+1]:0);Br[i]=(i<N-1?Br[i+1]:0);
    Cr[i]=(i<N-1?Cr[i+1]:0);Dr[i]=(i<N-1?Dr[i+1]:0);
    if(S[i]=='A')Ar[i]++;
    if(S[i]=='B')Br[i]++;
    if(S[i]=='C')Cr[i]++;
    if(S[i]=='?')Dr[i]++;
  }
  long ans=0;
  for(long i=0;i<N;i++){
    if(S[i]=='B'){
      ans=(ans+Al[i]*Cr[i]*p[Dl[i]+Dr[i]])%MOD;
      ans=(ans+Dl[i]*Cr[i]*p[Dl[i]-1+Dr[i]])%MOD;
      ans=(ans+Al[i]*Dr[i]*p[Dl[i]+Dr[i]-1])%MOD;
      ans=(ans+Dl[i]*Dr[i]*p[Dl[i]+Dr[i]-2])%MOD;     
    }
    if(S[i]=='?'){
      ans=(ans+Al[i]*Cr[i]*p[Dl[i]+Dr[i]-2])%MOD;
      ans=(ans+(Dl[i]-1)*Cr[i]*p[Dl[i]+Dr[i]-3])%MOD;
      ans=(ans+Al[i]*(Dr[i]-1)*p[Dl[i]+Dr[i]-3])%MOD;
      ans=(ans+(Dl[i]-1)*(Dr[i]-1)*p[Dl[i]+Dr[i]-4])%MOD;     
    }
  }
  cout<<ans;
}