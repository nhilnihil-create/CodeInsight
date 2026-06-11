#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  ll N, K;
  ll res=0;
  cin >> N>>K;

  ll a = N/K;
  res = a*a*a;

  if(K%2==0){
    if(N%K >=  K/2) a++;
    res += a*a*a;
  }

  cout << res << endl;
}
