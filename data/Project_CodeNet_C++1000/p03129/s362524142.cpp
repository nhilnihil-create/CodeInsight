#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,K;
  cin>>N>>K;
  int n=(N+1)/2;
  if(n>=K)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
