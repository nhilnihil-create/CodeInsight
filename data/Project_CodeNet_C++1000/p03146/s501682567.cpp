#include <bits/stdc++.h>
using namespace std;
#define rrep(i,j,n) for(int i = (int)(j); i < (int)(n); i++)

int main() {
	int n; cin >> n;
	rrep(i,1,1000001) {
		if(n==1||n==2||n==4) {
			cout << i+3 << endl;
			return 0;
		}
		if(n%2==0) n=n/2;
		else n=n*3+1;
	}
}