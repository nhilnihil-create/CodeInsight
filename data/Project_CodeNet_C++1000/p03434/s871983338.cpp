#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int n,an=0,bn=0,i=0;
	cin >> n;
	vector<int>a(n);
	vector<int>b(n);
	rep(i, n) {
		cin >> b.at(i);
	}
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	rep(i, n) {
		if (i % 2 == 0) {
			an += b.at(i);
		}
		else {
			bn += b.at(i);
		}
	}
	cout << an - bn << endl;
	return 0;
}