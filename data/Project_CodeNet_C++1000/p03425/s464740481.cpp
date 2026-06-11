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
  vec a(5);
  for(ll i=0;i<n;i++){
    string t;
    cin >> t;
    char b=t[0];
    if(b=='M')a[0]++;
    else if(b=='A')a[1]++;
    else if(b=='R')a[2]++;
    else if(b=='C')a[3]++;
    else if(b=='H')a[4]++;    
  }

  ll ans=0;
  for(ll i=0;i<5;i++){
    for(ll j=i+1;j<5;j++){
      for(ll k=j+1;k<5;k++){
        ans+=a[i]*a[j]*a[k];
      }
    }
  }

  cout << ans << endl;

}