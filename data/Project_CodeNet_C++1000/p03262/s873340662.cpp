#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
 
int main(){
  int n;
  cin >> n;
  vector<int> x(n+1);
  cin >> x[0];
  for(int i=1; i<=n; i++){
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  vector<int> diffs(n);
  for(int i=1; i<=n; i++){
    diffs[i-1] = x[i] - x[i-1];
  }
  sort(diffs.begin(), diffs.end());
  int ans = diffs[0];
  for(int i=0; i<n; i++){
    ans = gcd(ans, diffs[i]);
  }
  cout << ans << endl;
  return 0;
}
