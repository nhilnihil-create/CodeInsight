#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#include <numeric>
#include <bitset>
#include <cassert>
#include <functional>

using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

int main() {
	string S;
	int w;
	cin >> S >> w;
	int count = 0;
	for (int i = 0; i < S.length(); i += w) {
		cout << S[i];
	}
	cout << endl;
	return 0;
}