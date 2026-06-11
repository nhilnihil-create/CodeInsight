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
using ll = long long; 
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s,t;
	cin >> s >> t;
	vector<int>S(26,-1);
	vector<int>T(26,-1);
	rep(i,s.size()) {
		int a = s[i] - 'a';
		int b = t[i] - 'a';
		if(S[a] != -1 || T[b] != -1) {
			if(S[a] != b || T[b] != a) {
				cout << "No" << endl;
				return 0;
			}	
		}
		S[a] = b;
		T[b] = a;
	}
	cout << "Yes" << endl;
}