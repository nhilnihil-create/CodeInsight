#include <bits/stdc++.h>
using namespace std;

int s[1000];
int main() {
	int a,b; cin >> a >> b;
	s[0]=0;
	for(int i=1;i<=999;i++) {
		s[i]=s[i-1]+i;
	}
	cout << s[b-a]-b << endl;
}