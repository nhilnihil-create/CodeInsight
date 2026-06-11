#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n; 
  cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(a.begin(), a.end());
  ll b = a[n/2];
  ll ans = 0;
  for(int i=0; i<n; i++){
    ans += abs(a[i]-b);
  }
  cout << ans << endl;
  return 0;
}
