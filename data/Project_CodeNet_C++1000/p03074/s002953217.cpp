#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n,k;
string s;
vector<int>v;

void solve(){
  cin >> n >> k;
  cin >> s;
  char pre='0';
  int cnt=0;
  for(int i=0;i<n;i++){
    if(pre!=s[i]){
      v.push_back(cnt);
      cnt=1;
    }
    else cnt++;
    pre=s[i];
  }
  v.push_back(cnt);
  if(pre=='1')v.push_back(0);
  if(v.size() == 1){
		cout << v[0] << endl;
		return;
	}
  int sum=0;
  int x=0;
  for(int i=0;i<v.size();i++){
    sum+=v[i];
    if(i%2)x=max(sum,x);
    if(i-2*k>=0) sum-=v[i-2*k];
  }
  int ans=x;
  reverse(v.begin(),v.end());
  sum=0;
  x=0;
  for(int i=0;i<v.size();i++){
    sum+=v[i];
    if(i%2)x=max(sum,x);
    if(i-2*k>=0) sum-=v[i-2*k];
  }
  ans=max(ans,x);
  cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
