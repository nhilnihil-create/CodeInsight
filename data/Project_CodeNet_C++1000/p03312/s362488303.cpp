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
ll s[200100];

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>N;
  for(int i=1;i<=N;i++) cin>>s[i], s[i]+=s[i-1];

  int i=2,j=3,k=4;
  ll res = 1e18;
  while (j<=N-1) {
    while (s[j-1]-s[i-1] > s[i-1]) i++;
    ll a = max(s[i-2], s[j-1]-s[i-1]);
    ll b = s[j-1]-a;

    while (s[N]-s[k-1] > s[k-1]-s[j-1]) k++;
    ll c = max(s[k-2]-s[j-1], s[N]-s[k-1]);
    ll d = s[N]-s[j-1]-c;

    res = min(res, max(max(a,b),max(c,d))-min(min(a,b),min(c,d)));

    j++;
  }

  cout<<res<<endl;

  return 0;
}
