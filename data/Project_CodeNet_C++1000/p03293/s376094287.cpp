#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	string s, t;
    while (cin >> s >> t) {
        int flag = 0;
    	int tsize = t.size(), ssize = s.size();
   		for (int i = 0; i < ssize; i++) {
        	char a = s[ssize - 1];
        	s = a + s;
        	s = s.substr(0, ssize);
        	if (s == t) {
            	flag = 1, cout << "Yes\n";
            	break;
        	}
    	}
    	if (flag == 0) cout << "No\n";
    }
    return 0;
}