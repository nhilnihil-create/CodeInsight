#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void) {

	int num = 0, n;

	string a, b, c;

	cin >> n >> a >> b >> c;

	for (int k = 0; k < n; k++) {
		if (a[k] != b[k] && b[k] != c[k]&&c[k]!=a[k])num += 2;
		else if (a[k] != b[k] || b[k] != c[k]||c[k]!=a[k])num++;
		//printf("k==%d,num==%d\n", k, num);
	}

	cout << num << "\n";

	return 0;
}