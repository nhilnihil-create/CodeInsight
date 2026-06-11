#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;

int sum(int n) {
int sum = 0;
if (n <= 0) return 0;
while (n > 0) {
sum += n%10;
n /= 10;
}
return sum;
}

int main() {
  int n;
  cin >> n;
  int ans = INF;
  for(int i = 1; i < n; i++){
    ans = min(ans, sum(i)+sum(n-i));
  }
  cout<<ans<<endl;
  return 0;
}