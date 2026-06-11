#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF = 12;
int main(){
	int N;
	cin >> N;
	vector<int> D(N);
	for (int i = 0; i < N; i++){
		cin >> D[i];
	}
	vector<int> cnt(13, 0);
	cnt[0]++;
	for (int i = 0; i < N; i++){
		cnt[D[i]]++;
	}
	bool zero = false;
	if (cnt[0] >= 2 || cnt[12] >= 2){
		zero = true;
	}
	for (int i = 1; i <= 11; i++){
		if (cnt[i] >= 3){
			zero = true;
		}
	}
	if (zero){
		cout << 0 << endl;
	} else {
		int ans = 0;
		for (int i = 0; i < (1 << 11); i++){
			vector<int> t;
			for (int j = 0; j <= 12; j++){
				if (cnt[j] == 1){
					if (j == 0){
						t.push_back(0);
						t.push_back(24);
					} else if (j == 12){
						t.push_back(12);
					} else {
						if (i >> (j - 1) & 1){
							t.push_back(24 - j);
						} else {
							t.push_back(j);
						}
					}
				}
				if (cnt[j] == 2){
					t.push_back(j);
					t.push_back(24 - j);
				}
			}
			sort(t.begin(), t.end());
			int s = INF;
			int sz = t.size();
			for (int j = 0; j < sz - 1; j++){
				s = min(s, t[j + 1] - t[j]);
			}
			ans = max(ans, s);
		}
		cout << ans << endl;
	}
}