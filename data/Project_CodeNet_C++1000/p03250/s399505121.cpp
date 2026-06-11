#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define SIZE(a) int((a).size();
const int INF=INT_MAX;
int main(){
  vll a(3);
  rep(i,0,3){cin>>a[i];}
  sort(a.begin(),a.end());
  cout<<a[2]*10+a[0]+a[1]<<endl;
}