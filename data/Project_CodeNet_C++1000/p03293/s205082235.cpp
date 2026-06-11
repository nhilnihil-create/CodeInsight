#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	 string t;
	 cin >> t;
	 string s;
	 cin >> s;
	 t += t;
	 //cout << t << endl;
	 int n = (int)t.size();
	 int m = (int)s.size();
	 for (int i = 0; i + m < n; ++i) {
		 bool d = 1;
		 int p = 0;
		 for (int j = i; j < i + m; ++j) {
			 if (s[p] != t[j]) {
				 d = 0;
			 }
			 p++;
		 }
		 if (d) {
			 cout << "Yes";
			 return 0;
		 }
	 }
	 cout << "No";
}
