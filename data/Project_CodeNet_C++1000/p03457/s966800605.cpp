#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>t(N),x(N),y(N);
  for(int i=0;i<N;i++)cin>>t[i]>>x[i]>>y[i];

  int nx=0,ny=0;
  for(int i=0;i<N;i++){
    int d=abs(nx-x[i])+abs(ny-y[i]);
    int T;
    if(i==0)T=t[i];
    else T=t[i]-t[i-1];
    if(d>T){
      cout<<"No"<<endl;
      return 0;
    }
    if((T-d)%2){
      cout<<"No"<<endl;
      return 0;
    }
    nx=x[i];
    ny=y[i];
  }

  cout<<"Yes"<<endl;
  return 0;
}
