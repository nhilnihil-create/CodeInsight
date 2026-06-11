#include <bits/stdc++.h>
using namespace std;

int n;
string s;
long long f(int state) {
  vector<char> red, blue;
  for (int i=0; i<n; i++) {
    if ((state >> i) & 1) {
      red.push_back(s[i]);
    } else {
      blue.push_back(s[i]);
    }
  }
  int rest_red = n - red.size();
  int rest_blue = n - blue.size();
  long long dp[rest_red+1][rest_blue+1];
  for (int i=0; i<rest_red+1; i++) {
    for (int j=0; j<rest_blue+1; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i=2*n-1; i>=n; i--) {
    int num = 2*n - i;
    for (int j=max(num-rest_blue,1); j<=min(rest_red, num); j++) {
      if (s[i] == blue[j-1]) {
        dp[j][num-j] += dp[j-1][num-j];
      }
    }
    for (int j=max(num-rest_red, 1); j<=min(rest_blue, num); j++) {
      if (s[i] == red[j-1]) {
        dp[num-j][j] += dp[num-j][j-1];
      }
    }
  }
  return dp[rest_red][rest_blue];
}
int main() {
  cin>>n>>s;
  long long ans = 0;
  for (int i=0; i<(1<<n); i++) {
    ans += f(i);
  }
  cout<<ans<<endl;
}