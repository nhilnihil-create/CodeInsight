#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL << 60; 

ll N, K, h[100010];

int main()
{
  cin >> N >> K;
  for(int i = 1; i <= N; i++) cin >> h[i];
  
  sort(h+1,h+N+1,greater<ll>());
  
  ll maxMin = INF;
  for(ll i = 1; i <= N-K+1; i++)
  {
    if(h[i]-h[i+K-1] < maxMin)
      maxMin = h[i]-h[i+K-1];
  }
  cout << maxMin << endl;
}