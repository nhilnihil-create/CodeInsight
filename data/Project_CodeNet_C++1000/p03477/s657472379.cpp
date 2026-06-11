#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

int a,b,c,d;

int main()
{
  cin >> a >> b >> c >> d;
  int L = a+b, R = c+d;
  if(L > R) cout << "Left" << endl;
  else if(L == R) cout << "Balanced" << endl;
  else cout << "Right" << endl; 
}