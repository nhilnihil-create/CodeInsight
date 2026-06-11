#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(void)
{
	int n;
	cin >> n;

	vector <int> a;

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	std::sort(a.begin(), a.end());

	int big = a.at(a.size()-1);
	double half = big*0.5;
	int down = a.at(0);
	int up = a.at(a.size()-2);

	for (int i = 1; i < a.size()-2; i++) {
		int tmp = a.at(i);
		if (tmp < half) {
			down = tmp;
		} else {
			up = tmp;
			break;
		}
	}

	double diff_d = half-(double)down;
	double diff_u = (double)up - half;

	if (diff_d < diff_u) {
		cout << big << " " << down << endl;
	} else {
		cout << big << " " << up << endl;
	}
	return 0;
}
