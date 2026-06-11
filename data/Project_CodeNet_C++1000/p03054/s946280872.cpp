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

int H,W,N;
int sr, sc;
string s,t;
int l[200100],r[200100],u[200100],d[200100];

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>H>>W>>N>>sr>>sc>>s>>t;

  l[N]=d[N]=1;
  r[N]=W;
  u[N]=H;

  bool good = 1;
  for(int i=N-1;i>=0;i--) {
    l[i]=l[i+1],r[i]=r[i+1],d[i]=d[i+1],u[i]=u[i+1];
    switch (t[i]) {
    case 'U':
      u[i] = min(u[i]+1, H);
      break;
    case 'D':
      d[i] = max(d[i]-1, 1);
      break;
    case 'L':
      r[i] = min(r[i]+1, W);
      break;
    case 'R':
      l[i] = max(l[i]-1, 1);
      break;
    }
    // cout << i << ' ' << l[i] << ' ' << r[i] << ' ' << d[i] << ' ' << u[i] << endl;
    switch (s[i]) {
    case 'U':
      d[i]++;
      break;
    case 'D':
      u[i]--;
      break;
    case 'L':
      l[i]++;
      break;
    case 'R':
      r[i]--;
      break;
    }
    // cout << i << ' ' << l[i] << ' ' << r[i] << ' ' << d[i] << ' ' << u[i] << endl;
    if (d[i] > u[i] || l[i] > r[i]){
      good=0;
      break;
    }
  }

  if (!(l[0]<=sc && sc<=r[0] && d[0]<=sr && sr<=u[0])) good=0;

  cout << (good ? "YES\n" : "NO\n");

  return 0;
}
