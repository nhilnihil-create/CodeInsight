#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1001001001;


int main() {
  ll n,k;
  cin>>n>>k;
  ll cnt=0;
  if (k==0){
    cout<<ll(n*n);
    return 0;
  }
  for(ll i=k+1;i<=n;i++){//bの候補
    ll q=n/i;
    cnt+=q*(i-k);
  //  cout<<i<<'i'<<cnt<<endl;

    if ((q*i+k)<=n)cnt+=n-(q*i+k-1);
  //  cout<<cnt<<endl;
  }

cout<<cnt;
}
