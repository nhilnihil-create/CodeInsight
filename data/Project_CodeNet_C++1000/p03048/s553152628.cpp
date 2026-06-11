#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  int r,g,b,n;
  cin>>r>>g>>b>>n;

  int ans=0;
  rep(i,n+1){
    rep(j,n+1){
      // cout<<(n-r*i-j*g)<<endl;
      if((n-i*r-j*g)%b==0&&(n-i*r-j*g)>=0)ans++;
    }
  }

  cout<<ans<<endl;
  return 0;
}
