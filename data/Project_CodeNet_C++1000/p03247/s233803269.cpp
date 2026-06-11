#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
#define fin {cout<<-1<<endl;return 0;}
//template
int pw(int n,int k){
  int res=1;
  while(k){
    if(k&1)res*=n;//res%=MOD;
    n*=n;//n%=MOD;
    k>>=1;
  }
  return res;
}
//main
signed main(){
  //解説AC
  int N;cin>>N;
  std::vector<int> x(N),y(N);
  for(int i=0;i<N;i++)cin>>x[i]>>y[i];
  for(int i=0;i<N-1;i++)if(((x[i]+y[i])&1)!=((x[i+1]+y[i+1])&1))fin
  bool even=((x[0]+y[0])%2+1)%2;
  cout<<32+even<<endl;
  for(int k=pw(2,31);k;k/=2){
    if(k<pw(2,31))cout<<" ";
    cout<<k;
  }
  if(even)cout<<" "<<1;cout<<endl;
  for(int i=0;i<N;i++)x[i]-=even;
  std::vector<int> u(N),v(N);//u=x+y,v=x-y 45rotate
  for(int i=0;i<N;i++)u[i]=x[i]+y[i];
  for(int i=0;i<N;i++)v[i]=x[i]-y[i];
  for(int i=0;i<N;i++){
    string ans;
    int k=pw(2,31);
    while(k){
      if(u[i]>0&&v[i]>0){ans+="R";u[i]-=k;v[i]-=k;}
      else if(u[i]>0&&v[i]<0){ans+="U";u[i]-=k;v[i]+=k;}
      else if(u[i]<0&&v[i]>0){ans+="D";u[i]+=k;v[i]-=k;}
      else{ans+="L";u[i]+=k;v[i]+=k;}
      k/=2;
    }
    cout<<ans;if(even)cout<<"R";cout<<endl;
  }
}
