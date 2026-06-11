#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N,C;
  cin>>N>>C;
  vector<ll>x(N),v(N);
  for(int i=0;i<N;i++)cin>>x[i]>>v[i];

  vector<ll>suml(N+1);
  suml[0]=0;
  for(int i=1;i<=N;i++)suml[i]=suml[i-1]+v[i-1];

  vector<ll>sumr(N+1);
  sumr[0]=0;
  for(int i=1;i<=N;i++)sumr[i]=sumr[i-1]+v[N-i];

  ll anslr=0;
  vector<ll>maxll=suml;
  for(int i=1;i<=N;i++)maxll[i]-=x[i-1];
  for(int i=1;i<=N;i++)maxll[i]=max(maxll[i],maxll[i-1]);

  vector<ll>maxrr=sumr;
  for(int i=1;i<=N;i++)maxrr[i]-=C-x[N-i];
  for(int i=1;i<=N;i++)maxrr[i]=max(maxrr[i],maxrr[i-1]);
  // right -> left
  ll ansrl=0;

  for(int i=0;i<=N;i++){
    if(i==0)ansrl=max(ansrl,maxrr[N]);
    else ansrl=max(ansrl,maxrr[N-i]+suml[i]-2*x[i-1]);
  }

  // left -> right
  for(int i=0;i<=N;i++){
    if(i==0)anslr=max(anslr,maxll[N]);
    else anslr=max(anslr,maxll[N-i]+sumr[i]-2*(C-x[N-i]));
  }
  cout<<max(ansrl,anslr)<<endl;
  return 0;
}
