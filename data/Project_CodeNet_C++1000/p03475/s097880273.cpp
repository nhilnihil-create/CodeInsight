#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int c[n-1], s[n-1], f[n-1];
	for (int i = 0; i < n-1; i++)
		cin >> c[i] >> s[i] >> f[i];
	for (int i = 0; i < n-1; i++) {
		int t = 0;
		for (int j = i; j < n-1; j++) {
			if (t < s[j])
				t = s[j] + c[j];
			else {
				int tmp = t - s[j];
				int tmp1 = (tmp+f[j]-1)/f[j];
				t = s[j] + tmp1*f[j] + c[j];
			}
		}
		cout << t << endl;
	}
	cout << 0 << endl;
	return 0;
}
