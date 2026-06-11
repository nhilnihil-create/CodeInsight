#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() { 
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(),s1.end());
	sort(s2.rbegin(),s2.rend());
	if (s1 < s2) {
		cout << "Yes";
	}else {
		cout << "No";
	}
}
