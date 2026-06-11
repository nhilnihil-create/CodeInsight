#include<bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
//using namespace atcoder;

const ll mod=1000000007;//998244353;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n;
  cin >> n;
  vec a(100);
  a[0]=2;
  a[1]=1;

  for(ll i=0;i<90;i++){
    a[i+2]=a[i]+a[i+1];
  }

  cout << a[n] << endl;

  return 0;
}