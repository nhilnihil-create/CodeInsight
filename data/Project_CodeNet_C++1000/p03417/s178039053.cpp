#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;

int
main() 
{

  ll n,m; cin >> n >> m;

  if(n == 1 && m == 1){
    cout << 1 << endl;
  } else if(n == 2 && m == 2) {
    cout << 0 << endl;
  } else if(n == 1 || m == 1){
    cout << max(n, m) - 2 << endl;
  } else {
    cout << (n * m) - (2 * m) - (2 * n) + 4 << endl;
  }

}

