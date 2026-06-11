#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n >> s;

  vector<int> lblack(n+1);
  vector<int> rwhite(n+1);

  lblack[0] = 0;
  rwhite[n] = 0;
  rep(i,n){
    lblack[i+1] = lblack[i];
    if(s[i] == '#') lblack[i+1]++;
  }
  for(int i=n-1; i>=0; i-- ){
    rwhite[i] = rwhite[i+1];
    if(s[i] == '.') rwhite[i]++;
  }
  int res = INF;
  FOR(i, 0, n) {
    res = min( res, lblack[i] + rwhite[i]);
  }

  cout << res << endl;
}
