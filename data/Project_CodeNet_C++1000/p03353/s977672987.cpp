#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 5000;

int main() {
	string s;cin>>s;
	int k;cin>>k;
	int n=s.size();
	set<string> st;
	rep(i,k) rep(j,n-i) st.insert(s.substr(j,i+1));
	auto itr=st.begin();
	rep(i,k-1) ++itr;
	cout<<*itr<<endl;
}
