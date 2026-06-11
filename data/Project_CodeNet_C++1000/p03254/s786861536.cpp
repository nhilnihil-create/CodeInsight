#include<bits/stdc++.h>
using namespace std;
int main() {
	int N, x; cin >> N >> x;
	int a[N];
	for (int i = 0; i < N; i++)	cin >> a[i];
	sort(a, a + N);
	int res = 0;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if(sum + a[i] > x) {
			cout << res << endl;
			return 0;
		}
		else {
			sum += a[i];
			res++;
		}
	}
	if(sum == x) cout << N << endl;
	else cout << N-1 << endl;
	return 0;
}
