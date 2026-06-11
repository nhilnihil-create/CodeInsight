#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define ll long long
#define be(v) v.begin(), v.end()

int main() {
	string s; cin >> s;
	int count = 0;
	rep(i,s.size()-1) {
		if(s[i] == s[i+1]) {
			count ++;
			if(s[i] == '0') s[i+1] = '1';
			else s[i+1] = '0';
		}
	}
	cout << count << endl;
}
