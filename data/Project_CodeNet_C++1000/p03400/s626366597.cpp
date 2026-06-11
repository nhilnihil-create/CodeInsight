#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
	int n, d, x,A;
	cin >> n >> d >> x;
	int count = x;
	rep(i, n) {
		cin >> A;
		int tmp=1;
		int j = 0;
		while (true)
		{
			tmp = j * A + 1;
			if (tmp > d)break;
			count++;
			j++;
		}
	}
	cout << count << endl;
}