#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	 string s;
	 cin >> s;
	 bool d = 1;
	 //bool b = 1;
	 int cnt = 0;
	 int n = (int)s.size();
	 for (int i = 0; i < n; ++i) {
		 if (i != 0 && s[i] != 'C') {
			 if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
				 continue;
			 } else {
				 d = 0;
			 }
		 }
		 if (s[i] == 'C') {
			 cnt++;
		 }
	 }
	 int ap = 0;
	 for (int i = 2; i <= n - 2; ++i) {
		 if (s[i] == 'C') ap++;
	 }
	 if (s[0] == 'A' && ap == 1 && d && cnt == 1) {
		cout << "AC";
	}else {
		cout << "WA";
	}
		  
}
