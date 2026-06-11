#include <bits/stdc++.h>
#define MAX_SIZE 200005
using namespace std;
int n;
char s[MAX_SIZE];
int jin[MAX_SIZE], dian[MAX_SIZE];
int main() {
	cin >> n; 
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		dian[i] = dian[i - 1];
		jin[i] = jin[i - 1];
		if(s[i] == '.') dian[i]++;
		else jin[i]++;
	}
	int minn = 1e9;
	for(int i = 0; i <= n; i++) {
		int left, right;
		left = jin[i];
		right = dian[n] - dian[i];
		minn = min(minn, left + right);
	}
	cout << minn << endl;
	return 0;
}