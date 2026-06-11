#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

ll solve(ll n){
  ll ans=0;
  reps(i,n+1){
    if(n%i==0)ans++;
  }
  return ans;
}



int main()
{

  ll n,ans=0;;
  cin>>n;
  if(n<105){
    cout<<0<<endl;
    return 0;
  }

  for(int i=105;i<=n;i++){
    if(solve(i)==8&&i%2==1)ans++;
  }

  cout<<ans<<endl;
  return 0;
}
