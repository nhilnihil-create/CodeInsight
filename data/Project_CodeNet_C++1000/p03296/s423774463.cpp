#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>    
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <bitset>
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
// #define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int M = 1e9 + 7;
//__int128


signed main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  std::vector<int> a(n), f(n + 1);
  for(int i = 0; i < n; ++i) {
  	cin >> a[i];
  }
  f[0] = 1;
  std::vector<int> v;
  for(int i = 1; i < n; ++i) {
  	if(a[i] == a[i - 1]) {
  		f[i] = f[i - 1] + 1;
  	} else {
  		v.eb(f[i - 1]);
  		f[i] = 1;
  	}
  }
  v.eb(f[n - 1]);
  int res = 0;
  for(int i : v) {
  	res += i / 2;
  }
  cout << res << endl;
	return 0;
}