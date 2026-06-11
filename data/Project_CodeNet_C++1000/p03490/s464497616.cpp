#include<bits/stdc++.h>
using namespace std;
int N;
string s;
bool pos(vector<int> V, int obj)
{
  int Vsum = 0; for(auto x: V) Vsum += x;
  obj += Vsum; if(obj%2 != 0) return false;
  obj /= 2;
  if(obj > Vsum || obj < 0) return false;
  vector<bool> dp(Vsum+1, false); dp[0] = true;
  for(auto x: V)
    for(int i=Vsum-x; i>=0; --i)
      if(dp[i]) dp[i+x] = true;
  return dp[obj];
}
int main()
{
  int x, y; vector<int> A, B;
  cin >> s >> x >> y; s+='T';
  
  bool hatsu = true;
  int cnt = 0;
  bool ap = true;
  for(auto c: s)
  {
    if(c == 'T')
    {
      if(hatsu)
      {
        x -= cnt;
        hatsu = false;
      }
      else if(cnt)
      {
        if(ap) A.push_back(cnt);
        else B.push_back(cnt);
      }
      ap = !ap;
      cnt = 0;
    }
    else ++cnt;
  }
  if(pos(A, x) && pos(B, y)) puts("Yes");
  else puts("No");
}