#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;



int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> r(n);
	vector<pair<int, int>> b(n);

	for (int i = 0; i < n;i++) {
		int a, b;
		cin >> a >> b;
		r[i] = make_pair(a, b);
	}

	for (int i = 0; i < n;i++) {
		int c, d;
		cin >> c >> d;
		b[i] = make_pair(c, d);
	}

	sort(r.begin(), r.end());
	sort(b.begin(), b.end());
	vector<bool> made_pair(n,false);
	int cnt = 0;
	for (int i = 0; i < n;i++) {
		int j_maxY = -1;
		int maxY = -1;
		for (int j = 0; j < n; j++) {
			
			if ( b[i].first > r[j].first) {
				if (!made_pair[j] && b[i].second > r[j].second) {
					if (maxY < r[j].second) {
						maxY = r[j].second;
						j_maxY = j;
					}
				}
			}
			else {
				break;
			}
		}
		
		if (maxY != -1) {
			cnt++;
			made_pair[j_maxY] = true;
		}
	}

	cout << cnt << endl;
}