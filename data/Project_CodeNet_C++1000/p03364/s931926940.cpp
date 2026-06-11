#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
char S[305][305];
int main(){
  cin>>N;
  for(ll i=0;i<N;i++){
    string s;cin>>s;
    for(ll j=0;j<N;j++)
      S[i][j]=s[j];
  }
  ll ans=0;
  for(ll i=-(N-1);i<N;i++){
    bool judge=true;
    for(ll A=0;A<N;A++)
      for(ll B=0;B<N;B++)
        if(S[A][(B+i+N)%N]!=S[B][(A+i+N)%N]){judge=false;break;}
  if(judge)
    ans+=(N-abs(i));
      }cout<<ans<<endl;
   return 0;
}