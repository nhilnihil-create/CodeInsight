#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;
 
typedef long long ll;
 
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define left(x) x * 2
#define right(x) x * 2 + 1

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

#define ml " "
#define nl endl

#define lb lower_bound
#define ub upper_bound

#define fo(i, a, b) for (int i = a; i <= b; ++ i)
#define foo(i, a, b) for (int i = a; i >= b; -- i)

#define srt(a, n) sort(a, a + n)

const int N = 4e6 + 10;
const int sz = 1 << 17;
const int MOD = 1e9 - 7;
const int INF = 4e5 + 7;

main (){
	clog << "Ready\n";
	
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(a + b + 1, c) + b;
	
	cerr << '\n';
}