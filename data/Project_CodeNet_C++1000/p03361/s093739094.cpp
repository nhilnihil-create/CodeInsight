#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define req(i,n) for(int i = 1;i <=n;i++)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

//最大公約数
int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}

//最小公倍数
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}

//素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}



  








int main() {         
	int n, m;
	cin >> n >> m;
	char v[n][m];
    bool d = 1;
    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == '#') {
				int cnt = 0;
				if (i + 1 < n && v[i + 1][j] == '#')cnt++;
				if (i - 1 >= 0 && v[i - 1][j] == '#')cnt++;
				if (j + 1 < m && v[i][j + 1] == '#')cnt++;
				if (j - 1 >= 0 && v[i][j -1] == '#')cnt++;
				if (!cnt) {
					d = 0;
				} 
			}
		}
	}
    if (d) {
		cout << "Yes";
	}else {
		cout << "No";
	}
}