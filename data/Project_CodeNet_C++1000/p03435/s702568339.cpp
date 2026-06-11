
#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	vector<vector<int>> c(3,vector<int>(3,0));
	rep(i,3) rep(j,3) cin >> c[i][j];
	vector<int> a(3),b(3);
	a[0] = 0;
	b[0] = c[0][0];
	b[1] = c[0][1];
	b[2] = c[0][2];
	if(c[1][0]-b[0] == c[1][2]-b[2] && c[1][2]-b[2]==c[1][1]-b[1] && c[2][0]-b[0] == c[2][2]-b[2] && c[2][2]-b[2]==c[2][1]-b[1]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}