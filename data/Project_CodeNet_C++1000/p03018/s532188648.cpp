#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int dp[200100];
int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  string s;cin>>s;
  int N=s.size();

  ll res = 0;
  bool cc=0;
  for (int i=N-1;i>=0;i--) {
    if (i<N-1 && s[i]=='B' && s[i+1]=='C') dp[i] = dp[i+2]+1;
    else if (s[i]=='A') dp[i] = dp[i+1], res += dp[i];
  }

  cout << res << endl;

  return 0;
}
