#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main()
{
  ll N,L_0,L_1,L;
  cin >> N;
  L_0 = 2;
  L_1 = 1;

  if(N>=2)
  rep(i,N-1)
  {
    L = L_0 + L_1;
    L_0 = L_1;
    L_1 = L;
  }
  else if(N==1)
    L = L_1;
  cout << L << endl;

}
