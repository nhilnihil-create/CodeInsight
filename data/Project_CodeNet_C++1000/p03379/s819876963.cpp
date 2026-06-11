#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
int main(){
  ll N;
  cin>>N;
  vector<ll> x(N);
  vector<ll> xcopy(N);
  for(ll i=0;i<N;i++){
    cin>>x.at(i);
    xcopy.at(i)=x.at(i);
  }
  sort(x.begin(),x.end());
  ll midium=x.at(N/2-1);
  for(ll i=0;i<N;i++){
    if(xcopy.at(i)<=midium){cout<<x.at(N/2)<<endl;}
    else if(xcopy.at(i)>midium){cout<<x.at(N/2-1)<<endl;}
  }
}