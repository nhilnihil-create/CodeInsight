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
    
	ll n,k;
	cin >> n >> k;
	ll h[n+1];
	rep (i,n) cin >> h[i];
	

	sort(h,h+n);
	int i = 0;
ll mini = INF;
	while (k <= n){
		mini = min(mini,h[k-1]-h[i]);
		//cout << h[k-1] << " " << h[i]<< endl;
		k++;
		i++;
	}

	cout << mini << endl;
	

	
}



