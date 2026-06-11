#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Restaurant{
	int id;
	string name;
	int price;
}; 

bool price_cmp(const struct Restaurant& a, const struct Restaurant& b) {
	return a.price > b.price;
}

bool name_cmp(const struct Restaurant& a, const struct Restaurant& b) {
	return a.name < b.name;
}

int main() {
	int n;
	cin >> n;

	string s;
	int p;
	vector<struct Restaurant> guide;
	struct Restaurant temp;

	for (int i = 0; i < n; i++) {
		cin >> s >> p;
		temp.id = i+1;
		temp.name = s;
		temp.price = p;
		guide.push_back(temp);
	}

	sort(guide.begin(), guide.end(), price_cmp);
	stable_sort(guide.begin(), guide.end(), name_cmp);

	for (int i = 0; i < n; i++) {
		cout << guide[i].id << endl;
	}
	return 0;
}
