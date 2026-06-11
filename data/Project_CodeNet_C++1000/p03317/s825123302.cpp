#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
//const int INF = 1001001001;
const int MOD = 1000003;

int main(){
    int n, k;
    cin >> n >> k;
    vi a(n);
  	rep(i,n)cin >> a[i];
  	cout << 1 + (n-k + k-1 -1)/(k-1) << endl;
  	return 0;
}