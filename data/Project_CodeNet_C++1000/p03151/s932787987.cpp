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

int N;
ll a[100100], b[100100];

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>N;
  for(int i=0;i<N;i++) cin>>a[i];
  for(int i=0;i<N;i++) cin>>b[i];

  int res=0;
  ll s=0;
  vector<ll> v;
  for(int i=0;i<N;i++) {
    if (a[i] < b[i]) s += b[i]-a[i], res++;
    else v.pb(a[i]-b[i]);
  }
  sort(v.rbegin(),v.rend());

  for (ll k:v) {
    if (s==0) break;
    ll z = min(k,s);
    s-=z, res++;
  }

  cout << (s==0 ? res : -1) << endl;


  return 0;
}
