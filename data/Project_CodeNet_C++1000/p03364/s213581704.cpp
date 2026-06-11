#include<bits/stdc++.h>
#define EM 100000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
LL mod = 1e9+7;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int N;
	cin >> N;
	vector<vector<char>>	s(N, vector<char>(N));
	for(int i = 0;i < N;i++)	for(int j = 0;j < N;j++)	cin >> s[i][j];
	int ans = 0;
	int a, b;
	int d = 0;
	for(int p = 0;p < 2;p++){
		for(int i = 0;i < N;i++){
			if(p == 0){a = 0;b = i;}
			else	{a = i;b = 0;}
			bool f = true;
			for(int j = 0;j < N;j++){
				for(int k = j+1;k < N;k++){
					if(s[(j-a+N)%N][(k-b+N)%N] != s[(k-a+N)%N][(j-b+N)%N]){f = false;}
				}
			}
			if(f){ans += N-i;if(i == 0){d = N-i;}}
		}
	}
	cout << (ans-d) << endl;
}