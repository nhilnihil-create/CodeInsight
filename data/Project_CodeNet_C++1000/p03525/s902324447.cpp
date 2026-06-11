#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int N;
	vector <int> D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;
		D.push_back(d);
	}
	
	std::sort(D.begin(), D.end());

	vector <int> hours;
	hours.push_back(0);
	int pm = 1;
	for (int i = 0; i < N; i++) {
		hours.push_back(D[i]*pm);
		pm *= -1;
	}
	std::sort(hours.begin(), hours.end());
	hours.push_back(hours.at(0)+24);

	int ans = 12;
	for (int i = 0; i < hours.size()-1; i++)
		ans = min(ans, hours.at(i+1)-hours.at(i));

	cout << ans << endl;

  return 0;
}
