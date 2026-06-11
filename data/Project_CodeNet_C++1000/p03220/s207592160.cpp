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

  double n,t,a;
  cin >> n >> t >> a;
  double h[(int)n];
  for(ll i=0;i<n;i++)cin >> h[i];
  double m=inf;
  ll ans;
  for(ll i=0;i<n;i++){
    if(abs(a-(t-h[i]*6/1000))<m){
      ans=i;
      m=abs(a-(t-h[i]*6/1000));
    }
  }

  cout << ans+1 << endl;

}