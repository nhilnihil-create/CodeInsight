#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 60;

int main(int argc, char const *argv[])
{
	int n, a[MAX_N];
	vector<pair<int, int> > pos, neg, ans;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i]<0) neg.push_back(make_pair(a[i], i));
		else pos.push_back(make_pair(a[i], i));
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());

	if (neg.size()==0) {
		for (int i = 1; i < n; ++i) {
			if (a[i-1]>a[i]) {
				a[i]+=a[i-1];
				ans.push_back(make_pair(i-1, i));
			}
			else continue;
		}
	}
	else if (pos.size()==0) {
		for (int i = n-2; i >= 0; --i) {
			if (a[i+1]<a[i]) {
				a[i] += a[i+1];
				ans.push_back(make_pair(i+1, i));
			}
			else continue;
		}
	}
	else if (-1*neg[0].first > pos[pos.size()-1].first) {
		for (int i = 0; i < n; ++i) {
			a[i] += neg[0].first;
			ans.push_back(make_pair(neg[0].second, i));
		}
		for (int i = n-2; i >= 0; --i) {
			if (a[i+1]<a[i]) {
				a[i] += a[i+1];
				ans.push_back(make_pair(i+1, i));
			}
			else continue;
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			a[i]+=pos[pos.size()-1].first;
			ans.push_back(make_pair(pos[pos.size()-1].second, i));
		}
		for (int i = 1; i < n; ++i) {
			if (a[i-1]>a[i]) {
				a[i]+=a[i-1];
				ans.push_back(make_pair(i-1, i));
			}
			else continue;
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
	}
	return 0;
}