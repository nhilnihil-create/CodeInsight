#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cstring>
#include <iomanip>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
#define inf 280201280201280201
#define mn 200005
#define FLN "test"
#define int long long
typedef pair<int, int> ii;
//constance

//common data structures and templates
template<typename T>
struct SegmentTree{
};
//gb
int n;
int s[mn];
//functions here
void input(){
}
vector<ii> solve(int left, int right){
  vector<ii> ans;
  int l = left, r = right-1, lower=left;
  while(l<= r){
    int mid = (l+r)>>1;
    if(s[mid]-s[left-1] <= s[right]-s[mid]){
      lower = mid;
      l = mid+1;
    }
    else r = mid-1;
  }
  ans.push_back({s[lower]-s[left-1], s[right]-s[lower]});
  l = left, r = right-1; 
  int higher=left;
  while(l<= r){
    int mid = (l+r)>>1;
    if(s[mid]-s[left-1] >= s[right]-s[mid]){
      higher = mid;
      r = mid-1;
    }
    else l = mid+1;
  }
  ans.push_back({s[higher]-s[left-1], s[right]-s[higher]});
  return ans;
}

//#define LOCAL 1

signed main(signed argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	   freopen(FLN".inp", "r", stdin);
	   freopen(FLN".out", "w", stdout);
#endif
  cin >> n;
  for(int i=1; i<= n; ++i){
    cin >> s[i];
    s[i] += s[i-1];
  }
  //1- >i && i+1 -> n
  vector<ii> p, q;
  int ans= inf;
  for(int i=2; i<n ; ++i){
    //1->i
    p = solve(1, i);
    q = solve(i+1,n);
    for(ii x : p)
      for(ii y : q){
        int mi = min(min(x.first, x.second), min(y.first, y.second));
        int ma = max(max(x.first, x.second), max(y.first, y.second));
        ans = min(ans, ma - mi);
      }
  }
  cout << ans;
	return 0;
}
