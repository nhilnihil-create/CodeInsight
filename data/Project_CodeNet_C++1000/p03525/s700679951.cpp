#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
int gap[50 + 10];
int cnt[13];

int calc(int bit) {
	int pos[24] = {};//真ん中は12で
	pos[12]++;//高橋くん
	for (int i = 0; i < 12; i++) {
		if (cnt[i + 1] == 2) {
			pos[12 - (i + 1)]++;
			pos[(12 + (i + 1)) % 24]++;
		}
		else if (cnt[i + 1] == 1) {
			if ((bit >> i) & 1)pos[12 - (i + 1)]++;
			else pos[(12 + (i + 1)) % 24]++;
		}
	}
	int ret = 114514;
	for (int i = 0; i < 24; i++) {
		if (pos[i] == 0)continue;
		int d = 114514;
		if (pos[i] >= 2)d = 0;
		else if(pos[i] == 1){
			for (int j = 0; j < 24; j++) {
				if (pos[j] && j != i) d = min(d, (24 + j - i) % 24);
			}
		}
		ret = min(ret, d);
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> gap[i], cnt[gap[i]]++;;

	int ans = 0;

	if (cnt[0] >= 1) {
		cout << 0 << endl;
		return 0;
	}
	
	for(int i = 0; i <= 12; i++)
		if (cnt[i] >= 3) {
			cout << 0 << endl;
			return 0;
		}

	for (int bit = 0; bit < (1 << 12); bit++) {
		ans = max(ans, calc(bit));
	}

	cout << ans << endl;
	return 0;
}