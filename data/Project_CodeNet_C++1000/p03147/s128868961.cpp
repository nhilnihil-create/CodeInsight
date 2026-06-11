#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int n;
vector<int> vec;

int main()
{
  cin >> n;
  vec.resize(n, 0);
  int ans = 0;
  rep(i, n) cin >> vec[i];
  while(*max_element(vec.begin(), vec.end()) > 0) {
    int l = 0;
    while(vec[l] == 0) l++;
    ans++;
    while(l < n) {
      if (vec[l] != 0) {
        vec[l]--;
        l++;
      }
      if(vec[l] == 0) break;
    }
  }
  cout << ans << endl;

  return 0;
}