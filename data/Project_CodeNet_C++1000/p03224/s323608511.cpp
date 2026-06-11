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
	int subk = sqrt(2*N*4+1);
	if(subk*subk != 2*N*4+1){cout << "No" << endl; return 0;}
	int K = (subk+1)/2;
	vvint s(K);
	int cur = 1;
	for(int i = 0;i < K;i++){
		for(int j = i+1;j < K;j++){
			s[i].push_back(cur);
			s[j].push_back(cur++);
		}
	}
	cout << "Yes" << endl;
	cout << K << endl;
	for(int i = 0;i < K;i++){
		cout << (K-1) << " ";
		for(int j = 0;j < K-1;j++){cout << s[i][j] << " ";}
		cout << endl;
	}
}