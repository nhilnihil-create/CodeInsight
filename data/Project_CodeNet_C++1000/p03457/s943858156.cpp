#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() 
{
  int n, t[100002],x[100002],y[100002];
  cin >> n;
  t[0] = 0; x[0] = 0; y[0] = 0;
  for(int i = 1; i <= n; i++) 
    cin >> t[i] >> x[i] >> y[i];

  string ans = "Yes";
  for(int i = 1; i <= n; i++)
  {
    int T = t[i] - t[i-1];
    int X = abs(x[i] - x[i-1]);
    int Y = abs(y[i] - y[i-1]);
    if(X+Y == T) continue;
    else if((X+Y-T)%2 == 0 && X+Y < T) continue;
    else ans = "No";
  }
  cout << ans << endl;
}