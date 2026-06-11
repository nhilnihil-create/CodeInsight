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

  ll n,h;
  cin >> n >> h;
  vec a(n),b(n);
  for(ll i=0;i<n;i++)cin >> a[i] >> b[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll r=1000000000,l=0;
  ll half;
  ll p=upper_bound(b.begin(),b.end(),a[n-1])-b.begin();
  p=n-p;
  ll m=0;
  for(ll i=0;i<p;i++)m+=b[n-1-i];
  
  while(abs(r-l)>1){
    ll s=0;
    half=(r+l)/2;
    if(half<=p){
      for(ll i=0;i<half;i++){
        s+=b[n-1-i];
      }
    }
    else{
      s+=(half-p)*a[n-1];
      s+=m;
    }
    if(s>=h)r=half;
    else l=half;
  }

  cout << r << endl;
  //cout << p << endl;

  
  

}