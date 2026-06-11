#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  ll a,b,k;
  cin>>a>>b>>k;
  ll ag=min(a+k-1,b),bs=max(b-k+1,a);
  for(int i=a;i<=ag;i++)
    cout<<i<<"\n";

  for(int i=max(bs,ag + 1);i<=b;i++){
    cout<<i<<"\n";
  }

  return 0;
}
