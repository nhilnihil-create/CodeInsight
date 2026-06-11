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
    
	long long int N;
	cin >> N;

	long long int ansH, ansW, ansN = 0;

	for (int h = 1; h <= 3500; h++) {
		for (int w = 1; w <= 3500; w++) {
			long long int bunsi = N * h * w;
			long long int bunbo = 4 * h * w - N * w - N * h;
			
			if (bunbo <= 0)continue;
			if (bunsi % bunbo != 0)continue;



			ansN = bunsi / bunbo;
			if (ansN > 3500) {
				ansN = 0;
				continue;
			}
			ansH = h;
			ansW = w;
			break;

		}
		if (ansN != 0)break;
	}

	cout << ansH << " " << ansN << " " << ansW << endl;
	 
	return 0;

}


