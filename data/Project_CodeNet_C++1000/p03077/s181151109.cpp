#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  ll f=min(min(a,b),min(c,min(d,e)));
  cout<<(n+f-1)/f+4<<endl;
}