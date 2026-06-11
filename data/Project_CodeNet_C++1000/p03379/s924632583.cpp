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

  ll n;
  cin >> n;
  mat x;
  for(ll i=0;i<n;i++){
    ll a;
    cin >> a;
    x.push_back({a,i});
  }

  sort(x.begin(),x.end());

  ll b[n]={};

  for(ll i=0;i<n;i++){
    b[x[i][1]]=i+1;
  }

  //for(ll i=0;i<n;i++)cout << b[i] << endl;

  for(ll i=0;i<n;i++){
    if(b[i]<=n/2)cout << x[n/2][0] << endl;
    else cout << x[n/2-1][0] << endl;
  }



  

}