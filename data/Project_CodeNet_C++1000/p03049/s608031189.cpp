#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

int main() {

	int N;
	cin >> N;
	int a = 0, b = 0, c = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		if (tmp.front() == 'B' && tmp.back() == 'A')a++;
		else if (tmp.front() == 'B')b++;
		else if (tmp.back() == 'A')c++;
		for (int i = 0; i < tmp.size() - 1; i++) {
			if (tmp[i] == 'A' && tmp[i + 1] == 'B')ans++;
		}
	}

	if (a >= 1)ans += a - 1;
	if (a >= 1 && b >= 1)b--, ans++;
	if (a >= 1 && c >= 1)c--, ans++;
	ans += min(b, c);
	cout << ans << endl;

	return 0;
}