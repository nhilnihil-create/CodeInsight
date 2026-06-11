#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
int main() {

	//B
	string  s[100];
	//cin >> s >> t;
	int n;
	int p[100];
	cin >> n;
	int i;
	int num[100];
	for (i = 0; i < n; i++) {
		cin >> s[i] >> p[i];
		num[i] = i + 1;
	}

	string ss;
	int pp;
	int j;
	for (i = n-1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (s[j] > s[j + 1]) {
				ss = s[j];
				s[j] = s[j + 1];
				s[j + 1] = ss;
				pp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = pp;
				pp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = pp;
			}
			else if((s[j] == s[j+1]) && (p[j] < p[j+1])){
				pp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = pp;
				pp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = pp;
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << num[i] << endl;
	}
	return 0;
	//if (s < t) {
	//	cout << s;
	//}
	//else {
	//	cout << t;
	//}
	return 0;

	//A

	/*int a, p;
	cin >> a >> p;
	p = p + a * 3;
	cout << (p - (p % 2)) / 2 << endl;
	return 0;*/



}