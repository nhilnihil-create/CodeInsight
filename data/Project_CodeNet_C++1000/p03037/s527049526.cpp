#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int m,n;
  cin >> n >> m;
  int left=-1;
  int right=n+2;
  rep(i,m){
    int t_left, t_right;
    cin >> t_left >> t_right;
    left = max(left, t_left);
    right = min(right, t_right);
  }
  cout << max(right - left +1,0) << endl;
  
}