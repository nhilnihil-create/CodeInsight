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
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100;

int main() {
	string s;cin>>s;
	int l,r; char c;
	if(s.size()%2==0) {
		r=s.size()/2;
		c=s[s.size()/2-1];
	}
	else {
		r=s.size()/2+1;
		c=s[s.size()/2];
	}
	l=s.size()/2-1;
	while(c==s[l]&&c==s[r]&&l>=0&&r<=s.size()-1) {l--;r++;}
	cout<<r<<endl;
}
