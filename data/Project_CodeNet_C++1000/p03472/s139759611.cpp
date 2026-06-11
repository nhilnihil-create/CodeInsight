//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =1002;
const int MOD =1000000007;

signed main(){
  int n,h;
  cin>>n>>h;
  int a[n],b[n];
  for(int i=0;i<n;i++){cin>>a[i];
 cin>>b[i];}
  sort(a,a+n);sort(b,b+n);
  int ans=0,s=0;
  for(int i=n-1;i>=0;i--){
    if(b[i]<=a[n-1])break;
    s+=b[i];
    ans++;
    if(s>=h){
      cout<<ans<<endl;
      return 0;
    }
  }

  cout<<ans+(h-s-1)/a[n-1]+1<<endl;
}