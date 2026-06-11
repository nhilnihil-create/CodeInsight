#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll A[200000 + 10], B[200000 + 10];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i] >> B[i];
	ll ans = 0;
	ll minB = 1145141919810;
	int cntsame = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > B[i] && minB > B[i]) {
			minB = B[i];
		}
		if (A[i] == B[i])cntsame++;
		ans += B[i];
	}
	if(cntsame != N)cout << ans - minB << endl;
	else cout << 0 << endl;
	return 0;
}