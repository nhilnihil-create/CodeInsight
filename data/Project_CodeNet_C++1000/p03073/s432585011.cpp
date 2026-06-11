#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string s;
	cin >> s;

	string s1; // 1010...
	string s2; // 0101...
	int count1 = 0;
	int count2 = 0;
	rep(i, int(s.length())){
		s1 += '0';
		s2 += '1';
	}
	rep2(i, int(s.length()), 0, 2){
		s1.at(i) = '1';
		s2.at(i) = '0';
	}
	rep(i, int(s.length())){
		if (s.at(i) != s1.at(i))
			count1++;
		if (s.at(i) != s2.at(i))
			count2++;
	}
	// cout << s1 << endl;
	// cout << s2 << endl;
	// cout << count1 << endl;
	// cout << count2 << endl;
	if (count1 < count2)
		cout << count1 << endl;
	else
		cout << count2 << endl;
}