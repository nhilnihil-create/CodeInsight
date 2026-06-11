#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
  int N,X;
  cin>>N>>X;
	vector<int> x(N);
  int ans=1;
  rep(i,N){
      cin>>x[i];
  }
  sort(x.begin(),x.end());
  rep(i,N){
      if(i==0){
        ans=X-x[0];
      }
      else{
          ans=__gcd(ans,x[i]-x[i-1]);
      }
  }
  if(N==1){
    ans=abs(X-x[0]);
  }
  cout<<ans<<endl;
}
