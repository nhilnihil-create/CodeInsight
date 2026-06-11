#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<long long, long long> count;
		
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		count[tmp]++;
	}

	vector<pair<int,int>> bc(m);
	int in1, in2;
	for (int i = 0; i < m; i++) {
		cin >> in1 >> in2;
		bc[i] = make_pair( in2,in1 );
	}
	sort(bc.begin(), bc.end(), greater<pair<int,int>>());

	for (int i = 0; i < m; i++) {
		in1 = bc[i].second;
		in2 = bc[i].first;
//		cin >> in1 >> in2;
		auto itr = count.begin();
		while (itr->first < in2) {
			bool brkflg = false;
			while (itr->second > 0) {
				in1--;
				itr->second--;
				count[in2]++;
				if (in1 == 0) {
					brkflg = true;
					break;
				}
				if (itr->second == 0) {
					break;
				}

			}
			if (brkflg) { break; }
			itr=next(itr, 1);
		}
		itr = count.begin();
		while(itr->second==0){
			count.erase(itr->first);
			itr = count.begin();
		}

	}

	long long res=0;
	for (auto itr = count.begin(); itr != count.end(); itr++) {
		res += itr->first*itr->second;
	}
	cout << res << endl;
	return 0;

}