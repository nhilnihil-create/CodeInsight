#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<cmath>
#include<stack>
#include<string.h>
#include <iomanip>
#define rep(i,n) for(int i = 0;i<n;i++)
#define _GLIBCXX_DEBUG
using ll = long long; 
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>L;
int A,B,C;
int INF=1000000000;
int dfs(int i,int a,int b,int c) {

	if(i==n) {
		if(!a || !b || !c) return INF;
		if(a > 0 && b > 0 && c > 0) {
			return abs(a-A)+abs(b-B)+abs(c-C);
		}
	}

	int res0 = dfs(i+1,a,b,c);
	int res1 = dfs(i+1,a+L[i],b,c)+(a==0 ? 0 : 10);
	int res2 = dfs(i+1,a,b+L[i],c)+(b==0 ? 0 : 10);
	int res3 = dfs(i+1,a,b,c+L[i])+(c==0 ? 0 : 10);
	return min({res0,res1,res2,res3});
}
int main() {
	cin >> n >> A >> B >> C;
	L.resize(n);
	rep(i,n) cin >> L[i];
	cout << dfs(0,0,0,0) << endl;
}