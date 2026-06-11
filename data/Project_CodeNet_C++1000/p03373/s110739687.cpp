#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define min(a,b) ((a>b)? b:a)
#define max(a,b) ((a>b)? a:b)
int main()
{
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  vector<ll> cost;
  for(int i=0;i<=max(x,y);i++){
    ll tmp=i*2*c;
    if(x-i>0) tmp+=(x-i)*a;
    if(y-i>0) tmp+=(y-i)*b;
    cost.push_back(tmp);
  }
  cout<<*(min_element(cost.begin(),cost.end()));
}