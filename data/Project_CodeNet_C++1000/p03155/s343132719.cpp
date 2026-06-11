#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define DBG(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll p = 1e9+7;
const ll INF = 1LL << 60;

int main(){
  int n,h,w;
  cin>>n>>h>>w;
  cout<<(n-h+1)*(n-w+1)<<endl;
  return 0;
}
