#include<iostream>
#include<vector>
#define rep(i,m,n)for(int i=(int)m;i<(int)n;i++)
using namespace std;
void so(vector<int>* c) {
	for (int i = 0; i < c->size(); i++) {
		int max = c->at(i);
		int ii = i;
		for (int j = i; j < c->size(); j++) {
			if (max < c->at(j)) {
				max = c->at(j);
				ii = j;
			}
		}
		int swap = c->at(i);
		c->at(i) = max;
		c->at(ii) = swap;
	}

}
int main() {
	int n, a=0, b=0;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c.at(i);
	}
	so(&c);
	for (int i = 0; i < c.size(); i++) {
		if (i % 2 == 0)a += c.at(i);
		else b += c.at(i);
	}
	cout << a - b << endl;
}