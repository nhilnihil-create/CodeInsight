#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<int, int>> v;
	char key;
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			key = s[i];
			count = 1;
			continue;
		}
		if (s[i] != key) {
			v.push_back(make_pair(key - 48, count));
			key = s[i];
			count = 1;
		} else
			count++;

	}
	v.push_back(make_pair(key - 48, count));

	//for (auto e : v)
	//	printf("v: %d, %d\n", e.first, e.second);

	int right = 0;
	int kcount = 0;
	int maxsum = 0;
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			if (v[0].first == 1) {
				sum = v[0].second;
				right++;
			}
		} else {
			if (v[i-1].first == 1) {
				continue;
			}
			sum -= v[i-1].second;
			if (i-2 >= 0)
				sum -= v[i-2].second;
			kcount--;
		}
		while (kcount < k && right < v.size()) {
			if (v[right].first == 0) {
				kcount++;
				sum += v[right].second;
				right++;
				if (right < v.size()) {
					sum += v[right].second;
					right++;
				}
			}
		}
		//printf("left:%d, right:%d, sum:%d\n", i, right, sum);

		if (maxsum < sum)
			maxsum = sum;
	}
	cout << maxsum << endl;
	return 0;
}