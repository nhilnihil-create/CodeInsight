#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
int main() {
  int n;
  vector<int>v(3);
  rep(i, 0, 3)cin >> v[i];
  cin >> n;
  sort(v.begin(), v.end(), greater<int>());
  int cnt = 0;
  int m = n/v[0]; 
  rep(i, 0, m+1){
      int tempn = n;
      tempn -= v[0]*i;
      while(tempn >=0){
          if(tempn%v[2]==0){
              cnt++;
              //cout << tempn << endl;
           }
          tempn -= v[1];
        }
    }
  cout << cnt << endl;
}