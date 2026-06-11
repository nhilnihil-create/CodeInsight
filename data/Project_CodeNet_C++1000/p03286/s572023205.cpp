#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n,m;
  cin >> n;
  m=n;

  vec v;

  ll c=1;
  while(m!=0){
    ll a=(ll) pow(2,c);
    if(abs(m)%a!=0){
      v.push_back(1);
      if(c&1){
        m-=(ll) pow(2,c-1);
      }
      else{
        m+=(ll) pow(2,c-1);
      }
    }
    else{
      v.push_back(0);
    }
    c++;
  }

  if(v.size()==0)v.push_back(0);

  reverse(v.begin(),v.end());

  for(ll i=0;i<v.size();i++)cout << v[i] ;
  cout << endl;

}