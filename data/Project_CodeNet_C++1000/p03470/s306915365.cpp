#include<iostream>
#include<vector>
using namespace std;
void sortt(vector<int>* a) {
	for (int i = 0; i < a->size(); i++) {
		int min = a->at(i);
		int iii = i;
		for (int j = i; j < a->size(); j++) {
			if (min > a->at(j)) {
				iii = j;
				min = a->at(j);
			}
		}
		int swap = a->at(i);
		a->at(i) = min;
		a->at(iii) = swap;
	}

}
int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d.at(i);
	}
	sortt(&d);
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (d.at(i) == d.at(j)) {
				count++;
				i++;
			}
		}
	}
	cout << d.size() - count << endl;
}