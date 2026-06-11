#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  char c;
  cin >> c;
  string ans;
  if(c == 'A') ans = "T";
  else if(c == 'T') ans = "A";
  else if(c == 'G') ans = "C";
  else ans = "G";
  cout << ans << endl;
}