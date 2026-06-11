#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  a += b; c += d;
  if(a == c) cout << "Balanced" << endl;
  else if(a < c) cout << "Right" << endl;
  else if(a > c) cout << "Left" << endl;
}