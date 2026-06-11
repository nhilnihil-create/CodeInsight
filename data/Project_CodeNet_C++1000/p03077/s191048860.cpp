#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll x,a,m=10000000000000000,i;
int main(){
  for(cin>>x;i<5;++i)cin>>a,m=min(m,a);
  cout<<(x-1)/m+5;;
}