#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string s;
	cin >> s;
	map<int, int> d;
	int h = 0, m;
	d.insert(make_pair(h, 0));
	for (auto c : s) {
		h ^= 1 << c - 'a';
		m = -1;
		for (int i = 0; i < 26; i++) {
			auto it = d.find(h ^ 1 << i);
			if (it != d.end() && (m < 0 || it->second < m))
				m = it->second;
		}
		auto r = d.insert(make_pair(h, m + 1));
		if (r.second)
			continue;
		if (r.first->second > m)
			r.first->second = m + 1;
		else
			m = r.first->second;
	}
	cout << m + 1 << endl;
	return 0;
}
