#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;

vector<int> check;

int
main() 
{

  int n; cin >> n;
  vector<int> arr(n);
  ll ans = 0;
  rep(i, 0, n){
    int tmp;
    cin >> tmp;
    ans += tmp - 1 % tmp;
  }
  
  cout << ans << endl;

}


