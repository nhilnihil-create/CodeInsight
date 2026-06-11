#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll a,b,c;cin>>a>>b>>c;
  if(a+b>=c)cout<<b+c<<endl;
  else cout<<a+b+b+1<<endl;
  return 0;
}
