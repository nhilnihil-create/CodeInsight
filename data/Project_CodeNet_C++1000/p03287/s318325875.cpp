#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000
int kaizyou(int n){
int ans=1;
  for(int i=1;i<=n;i++){
    ans*=i;
  }
  return ans;
}

signed main()
 {
  int n,m;
  cin>>n>>m;
  int a[n];
  rep(i,n){cin>>a[i];}
  vector<int>s(n+1);

  rep(i,n+1){
      if(i==0){s[i]=0;}
      else {s[i]=(s[i-1]+a[i-1])%m;}
  }
  sort(s.begin(),s.end());
  int ans=0,onaji=1;
  rep(i,n){
    if(s[i]==s[i+1]){
      onaji++;
    }
    else{
      ans+=((onaji-1)*onaji)/2;
      onaji=1;
    }
  }
  ans+=((onaji-1)*onaji)/2;
  cout<<ans;
 }
