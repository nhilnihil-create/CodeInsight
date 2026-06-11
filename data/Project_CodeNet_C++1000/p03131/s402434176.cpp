#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  ll K, A, B;
  ll res=1;
  ll m = 0;
  cin >> K >> A >> B;

  while(K > 0) {
    if(K >=2 && res >=A && (B-A) >= 2) {
      res += B-A;
      K-=2;
    }
    else {
      res++;
      K--;
    }
    //printf("K=%lld bis#:%lld\n", K, res);                                              
  }

  cout << res << endl;
}