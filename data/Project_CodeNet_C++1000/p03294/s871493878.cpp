#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  ll n;
  ll a[5000];
  cin>>n;
  rep(i,n)cin>>a[i];

  ll sum=0;
  rep(i,n){
    sum+=a[i]-1;
  }

  cout<<sum<<endl;
  return 0;
}
