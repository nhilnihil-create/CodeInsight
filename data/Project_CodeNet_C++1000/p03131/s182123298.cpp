#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
  ll k, a, b; cin >> k >> a >> b;
  if(b-a <= 2 || a >= k){
    cout << k+1 << endl;
  }
  else{
    ll t = (k-a+1)/2;
    cout << b+(b-a)*(t-1)+(k-a-1) % 2 << endl;
  }
  system("pause");
}