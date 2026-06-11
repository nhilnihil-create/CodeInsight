#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n;cin>>n;
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int ans = 0;
	int mighty = 0;
	int A = 0;
	int B = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < a[i].size(); j++) {
			if (a[i][j - 1] == 'A' && a[i][j] == 'B'){
				ans ++;
			}
		}
		if (a[i][0] == 'B' && a[i][a[i].size() - 1] == 'A'){
			mighty++;
		}
		else if (a[i][a[i].size() - 1] == 'A')A++;
		else if (a[i][0] == 'B')B++;
	}
	// cout << A << " " << B << " " << mighty << endl;
	int tmp = 0;
	if (mighty != 0){
		ans +=  mighty - 1;
		if (A != 0){
			B++;
		}
		if (B != 0)A++;
	}
	ans += min(A,B);
	cout << ans << endl;

	return 0;
}