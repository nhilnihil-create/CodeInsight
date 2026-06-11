#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int MAX=max({a,b,c});
  int ans=a+b+c-MAX;
  rep(i,k)
    MAX*=2;
  cout<<ans+MAX<<endl;

  return 0;
}
