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

int n,A,B,C;

vector<int>L;
int INF = 100000000;

int rec(int i,int a,int b,int c) {
	if(i==n) {
		if(!a || !b || !c)return INF;
		return abs(a-A)+abs(b-B)+abs(c-C)-30;
	}
	int res0 = rec(i+1,a,b,c);
	int res1 = rec(i+1,a+L[i],b,c)+10;
	int res2 = rec(i+1,a,b+L[i],c)+10;
	int res3 = rec(i+1,a,b,c+L[i])+10;
	
	return min({res0,res1,res2,res3});   
}

int main() {
	cin >> n >> A >> B >> C;
	L.resize(n);
	rep(i,n) cin >> L[i];
	cout << rec(0,0,0,0) << endl;
}
