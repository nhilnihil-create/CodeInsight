#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;


int main() {
    int x;
	cin >> x;
	bool a[1001]={false};
	a[1]=true;
	for (double i = 2;i <= 1000;i++){
		for (double j = 2;pow(i,j) <= 1000;j++){
		
			a[(int)pow(i,j)] = true;
			//cout << (int)pow(i,j) << "  " << int(pow(i,j)) << endl;
			
		}
	}
	
	for (int i = x;i>=0;i--){
		if (a[i]) {
			cout << i << endl;
			return 0;
		}
		
		}
	}



