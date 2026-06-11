#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

vector<int> Da;
ll Ma[1000010];//正順
ll Ca[1000010];//逆順
ll MC[1000010];//逆順

int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;

	for (int i = 0;i < N;i++) {
		if (S[i] == 'D')Da.push_back(i);
	}

	if (S[0] == 'M')Ma[0] = 1;
	for (int i = 1;i < N;i++) {
		Ma[i] += Ma[i - 1];
		if (S[i] == 'M')Ma[i]++;
	}

	if (S[N - 1] == 'C')Ca[N - 1] = 1;
	for (int i = N - 2;i >= 0;i--) {
		Ca[i] += Ca[i + 1];
		MC[i] += MC[i + 1];
		if (S[i] == 'C')Ca[i]++;
		if (S[i] == 'M')MC[i] += Ca[i + 1];
	}

	int Q, k;
	ll ans;
	cin >> Q;
	for (int i = 0;i < Q;i++) {
		cin >> k;
		ans = 0;
		for (int j : Da) {
			ans += MC[j + 1];
			if (j + k >= N)continue;
			ans -= MC[j + k];
			ans -= (Ma[j + k - 1] - Ma[j])*(Ca[j + k]);
		}
		cout << ans << endl;
	}
}