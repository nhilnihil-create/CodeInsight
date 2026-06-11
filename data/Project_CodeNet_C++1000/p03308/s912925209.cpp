#include<bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef vector<int>     vi;
typedef pair<int,int>   pi;
typedef map<int,int>    mi;

#define F               first
#define S               second
#define pb              push_back
#define mp              make_pair
#define M               1000000007
#define SQ(a)           (a)*(a)
#define rep(i,a,b)      for(int i=a; i<b; i++)

void solve(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &x:v) cin >> x;
  int mn = *min_element(v.begin(), v.end());
  int mx = *max_element(v.begin(), v.end());

  cout << mx - mn << endl;
}
int main(){
    //int t; cin >> t; while(t--)
    solve();

    return 0;
}
