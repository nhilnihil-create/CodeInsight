#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin>>n;
  ll s=0;
if (n==0){
  cout<<0;
  return 0;
}

  vector<ll> ans(50);
  ll now=2;
  ll i=0;
  while(n!=0){
  //  if (n==0)break;
//  cout<<n<<endl;
    if (n%now!=0){
      ll temp=n%now;
      if (temp<0)temp+=now;
      ans[i]=1;
     if(i%2==0)n-=temp;
     if(i%2==1)n+=temp;

  //    if (i%2==1)n-=now;
    }
    now*=2;
    i++;
  }
  for(int j=i-1;j>=0;j--){
    cout<<ans[j];
  }

}
