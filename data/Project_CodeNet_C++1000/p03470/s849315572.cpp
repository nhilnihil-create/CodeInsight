#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vi d(n);
  rep(i, n)cin >> d[i];

  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  int ans=0, m=101;
  rep(i, n){
    if(m>d[i]){
      ans++;
      m=d[i];
    }
  }

  cout << ans << endl;

  return 0;
}