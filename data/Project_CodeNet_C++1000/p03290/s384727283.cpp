#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;



int main() {
	int d;
	int g;
	cin >> d >> g;

	vector<int> p(d);
	vector<int> c(d);
	vector<int> tot(d);
	for (int i = 0; i < d; i++) {
		int pp;
		int cc;
		cin >> pp >> cc;
		p.at(i) = pp;
		c.at(i) = cc;
		tot.at(i) = pp * (i + 1) * 100 + cc;
	}

	auto piter = max_element(p.begin(), p.end());
	int pmax = *piter;
	int ans = (pmax + 1) * (pmax + 1);
	for (int bit = 0; bit < (1 << d); bit++) {
		int pts = 0;
		int count = 0;
		vector<int> pcopy = p;
		int pos = -1;
		for (int i = 0; i < d; i++) {
			// fully solve
			if (bit & (1 << i)) {
				pts += tot.at(i);
				count += p.at(i);
				pcopy.at(i) = 0;
			}
			else {
				pos = max(pos, i);
			}
		}
	
		if (pos >= 0) {
			for (int j = 1; j < p.at(pos); j++) { // p: # of questions; pos + 1 = point/100. Do not fully solve the questions
				if (pts < g) {
					pts += (pos + 1) * 100;
					count += 1;
				}
				else {
					break;
				}
			}
		}
		if(pts >= g) ans = min(ans, count);
	}

	cout << ans << endl;
	return 0;
}