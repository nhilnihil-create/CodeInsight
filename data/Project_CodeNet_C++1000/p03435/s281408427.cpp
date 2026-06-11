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



  








      

 
int a[3];
int b[3];
int c[3][3];
 
int main() {
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cin>>c[i][j];
		}
	}
	a[0]=0;
	a[1]=c[1][0]-c[0][0];
	a[2]=c[2][0]-c[0][0];
	b[0]=c[0][0];
	b[1]=c[0][1];
	b[2]=c[0][2];
    string ans="Yes";
	for(int i=0;i<3;i++) {
		for (int j=0;j<3;j++) {
			if(a[i]+b[j]!=c[i][j]) ans="No";
		}
	}
	cout << ans << endl;
}