#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX

const double EPS = 1e-14;
const double PI  = acos(-1.0);


int main(){
  string s;
  cin >> s;

  vector<int> nums(3, 0);

  REP (i, s.size()) {
    nums[s[i] - 'a']++;
  }

  sort(nums.begin(), nums.end());

  if (nums[2] - nums[1] > 1 || nums[2] - nums[0] > 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
