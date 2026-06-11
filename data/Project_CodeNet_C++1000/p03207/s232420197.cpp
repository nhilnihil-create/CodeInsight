#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin>>n;
  int p[10010];
  rep(i,n)cin>>p[i];
  sort(p,p+n,greater<int>());
  ll sum=0;
  sum+=p[0]/2;
  for(int i=1;i<n;i++){
    sum+=p[i];
  }

  cout<<sum<<endl;
  return 0;
}
