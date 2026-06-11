#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int f[n+1]={}, b[n+1]={};
  for(int i=1; i<=n; i++){
    if(s[i-1]=='W') f[i] = f[i-1] + 1;
    else f[i] = f[i-1];
    
    if(s[n-i]=='E') b[n-i] = b[n-i+1] + 1;
    else b[n-i] = b[n-i+1];
  }
  int ans = n;
  for(int i=0; i<n; i++){
    ans = min(ans, f[i]+b[i+1]);
  }
  cout << ans << endl;
  return 0;
}
