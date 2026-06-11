#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  ll n, m=10000000000000009;
  cin >> n;
  for(int i=0; i<5; i++){
    ll tmp;
    cin >> tmp;
    m = min(m, tmp);
  }
  ll ans = n/m+4;
  if(n%m!=0) ans++;
  cout << ans << endl;
  return 0;
}
