#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 3e3 + 10;

vector<double> DP(MAX, 0);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	DP[0] = 1;

	for(int i = 1; i <= N; i++){
		double x;
		cin >> x;

		for(int j = i-1; j >= 0; j--){
			DP[j+1] += DP[j]*x;
			DP[j] *= (1 - x);
		}
	}

	double ans = 0;
	for(int i = (N + 1)/2; i <= N; i++) ans += DP[i];

	cout << fixed << setprecision(10);
	cout << ans << endl;
	return 0;
}
