#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N;
pll goal[1000];
vector<ll> d;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> goal[i].first >> goal[i].second;
	}

	int amari = (abs(goal[0].first) + abs(goal[0].second)) % 2;
	for (int i = 0; i < N; i++) {
		if (amari != ((abs(goal[i].first) + abs(goal[i].second)) % 2)) {
			cout << "-1" << endl;
			return 0;
		}
		goal[i] = make_pair(goal[i].first + goal[i].second, goal[i].first - goal[i].second);
	}

	for (int i = 30; i >= 0; i--) {
		d.push_back((1 << i));
	}

	if (amari == 0)d.push_back(1);

	cout << d.size() << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d[i];
		if (i != d.size() - 1)cout << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < d.size(); j++) {

			int dx, dy;

			if (goal[i].first >= 0) {
				goal[i].first -= d[j];
				dx = 1;
			}
			else {
				goal[i].first += d[j];
				dx = -1;
			}

			if (goal[i].second >= 0) {
				goal[i].second -= d[j];
				dy = 1;
			}
			else {
				goal[i].second += d[j];
				dy = -1;
			}

			if (dx == 1 && dy == 1)cout << "R" ;
			else if (dx == 1 && dy == -1)cout << "U";
			else if (dx == -1 && dy == 1)cout << "D";
			else cout << "L";

		}
		cout << endl;
	}

	return 0;
}