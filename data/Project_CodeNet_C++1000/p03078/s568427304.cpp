#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll A[1010], B[1010], C[1010];
int main()
{
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	for (int i = 0; i < X; i++) cin >> A[i];
	for (int i = 0; i < Y; i++) cin >> B[i];
	for (int i = 0; i < Z; i++) cin >> C[i];
	sort(A, A + X, greater<ll>());
	sort(B, B + Y, greater<ll>());
	sort(C, C + Z, greater<ll>());
	vector<ll> V;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			V.push_back(A[i] + B[j]);
		}
	}
	sort(V.begin(), V.end(), greater<ll>());
	vector<ll> ans;
	for (int i = 0; i < min((int)V.size(), K); i++) {
		for (int j = 0; j < Z; j++) {
			ans.push_back(V[i] + C[j]);
		}
	}
	sort(ans.begin(), ans.end(), greater<ll>());
	for (int i = 0; i < K; i++) {
		cout << ans[i] << endl;
	}
}
