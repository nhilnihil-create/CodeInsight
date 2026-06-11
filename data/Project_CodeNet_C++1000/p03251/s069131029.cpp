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

  ll n,m,x,y;
  cin >> n >> m >> x >> y;

  ll a[n],b[m];
  for(ll i=0;i<n;i++)cin >> a[i];
  for(ll i=0;i<m;i++)cin >> b[i];

  sort(a,a+n);
  sort(b,b+m);

  for(ll i=-100;i<101;i++){
    if(x<i && i<=y && a[n-1]<i && i<=b[0]){
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;

}