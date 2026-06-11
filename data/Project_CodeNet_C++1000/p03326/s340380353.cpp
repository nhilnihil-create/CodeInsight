#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,M;
  cin>>N>>M;
  vector<ll> A0(N,0);
  vector<ll> A1(N,0);
  vector<ll> A2(N,0);
  vector<ll> A3(N,0);
  vector<ll> A4(N,0);
  vector<ll> A5(N,0);
  vector<ll> A6(N,0);
  vector<ll> A7(N,0);
  for(int i=0; i<N; i++){
    ll x,y,z;
    cin>>x>>y>>z;
    A0[i]=x+y+z;
    A1[i]=x+y-z;
    A2[i]=x-y+z;
    A3[i]=x-y-z;
    A4[i]=-x+y+z;
    A5[i]=-x+y-z;
    A6[i]=-x-y+z;
    A7[i]=-x-y-z;
  }
  sort(A0.begin(), A0.end(), greater<ll>());
  sort(A1.begin(), A1.end(), greater<ll>());
  sort(A2.begin(), A2.end(), greater<ll>());
  sort(A3.begin(), A3.end(), greater<ll>());
  sort(A4.begin(), A4.end(), greater<ll>());
  sort(A5.begin(), A5.end(), greater<ll>());
  sort(A6.begin(), A6.end(), greater<ll>());
  sort(A7.begin(), A7.end(), greater<ll>());
  ll ans=0;
  ll tmp0=0;
  ll tmp1=0;
  ll tmp2=0;
  ll tmp3=0;
  ll tmp4=0;
  ll tmp5=0;
  ll tmp6=0;
  ll tmp7=0;
  for(int i=0; i<M; i++)
    tmp0+=A0[i];
  for(int i=0; i<M; i++)
    tmp1+=A1[i];
  ans=max(tmp0, tmp1);
  for(int i=0; i<M; i++)
    tmp2+=A2[i];
  ans=max(ans, tmp2);
  for(int i=0; i<M; i++)
    tmp3+=A3[i];
  ans=max(ans, tmp3);
  for(int i=0; i<M; i++)
    tmp4+=A4[i];
  ans=max(ans, tmp4);
  for(int i=0; i<M; i++)
    tmp5+=A5[i];
  ans=max(ans, tmp5);
  for(int i=0; i<M; i++)
    tmp6+=A6[i];
  ans=max(ans, tmp6);
  for(int i=0; i<M; i++)
    tmp7+=A7[i];
  ans=max(ans, tmp7);
  cout<<ans<<endl;
}
