#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n, w, sum = 0; string s; cin >> s >> w;
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		i += w - 1;
	}
	cout << endl;
	cin >> n;
}