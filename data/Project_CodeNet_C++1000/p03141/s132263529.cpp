#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <vector>
#include <numeric>

using namespace std;



bool gooddis(long long int n) {

	long long int a = 0;

	while (n >= a * a) {
		if (n == a * a)return true;
		a++;
	}

	return false;
}



vector<pair<long long int, long long int>> getPrimeElements(long long int num) {

	long long int firstnum = num;

	vector<pair<long long int, long long int>> result;
	pair<long long int, long long int> wk;

	if (num % 2 == 0) {
		wk.first = 2;
		wk.second = 0;
		while (num % 2 == 0) {
			wk.second++;
			num /= 2;
		}

		result.push_back(wk);
	}

	long long int waru = 3;

	while (true) {

		if (num % waru == 0) {
			wk.first = waru;
			wk.second = 0;
			while (num % waru == 0) {
				wk.second++;
				num /= waru;
			}

			result.push_back(wk);
		}
		waru += 2;

		if (waru * waru > num) break;

	}

	if (num != 1) {
		wk.first = num;
		wk.second = 1;
		result.push_back(wk);

	}

	return result;
}


int main()
{
    
	int n;
	cin >> n;

	vector<pair<long long int, long long int>> gohan(n);

	for (int i = 0; i < gohan.size(); i++) {
		cin >> gohan[i].first;
		cin >> gohan[i].second;
	}

	vector<long long int> wa(n);
	long long int aokisum = 0;
	for (int i = 0; i < wa.size(); i++) {
		wa[i] = gohan[i].first + gohan[i].second;
		aokisum += gohan[i].second;
	}

	sort(wa.begin(), wa.end(), greater<long long int>());

	int gohantaberu = (n + 1) / 2;

	long long int ans = (-1) * aokisum;

	for (int i = 0; i < gohantaberu; i++) {
		ans += wa[2 * i];
	}

	cout << ans << endl;
	 
	return 0;

}


