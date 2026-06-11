#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int A, B, K;

	cin >> A >> B >> K;

	int count = 0;
	vector<int> vc;
	for (int loop = A; loop <= B; ++loop) {
		if (count < K) {
			vc.push_back(loop);
		} else {
			break;
		}
		++count;
	}

	count = 0;
	for(int i = B; i > A; --i) {
		if (count < K) {
			vc.push_back(i);
		} else {
			break;
		}
		++count;
	}

	sort(vc.begin(), vc.end());

	vc.erase( unique(vc.begin(), vc.end()), vc.end() );

	for(int i = 0; i < vc.size(); i++) {
		cout << vc[i] << endl;
	}

	return 0;
}
