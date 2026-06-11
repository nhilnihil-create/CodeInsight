#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
int MOD=1000000007;

signed main() {
int n;
cin>>n;
vector<int>a(n);
vector<int>b(n);
vector<int>c(n);
rep(i,n)cin>>a[i];
rep(i,n)cin>>b[i];
rep(i,n)cin>>c[i];
sort(a.begin(),a.end());
sort(b.begin(),b.end());
sort(c.begin(),c.end());
int ans=0;
rep(i,n){
  int d1,d2;
  d1=distance(a.begin(),lower_bound(a.begin(),a.end(),b[i]));
  d2=n-distance(c.begin(),upper_bound(c.begin(),c.end(),b[i]));
  ans+=d1*d2;
}
cout<<ans<<endl;
}
