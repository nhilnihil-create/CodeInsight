#include <iostream>
using namespace std;
int main(){
	int a[2][100];
	int n;
	int total=0;
	int max = 0;
	cin >> n;
	for (int i = 0;i < 2;i ++) {
		for (int j = 0;j < n;j++)
			cin >> a[i][j];
	}
	for (int c = 0;c < n;c++) {
		for (int i = 0;i <= c;i++) total += a[0][i];
		for (int j = c;j < n;j++) total += a[1][j];
		if (max < total) max = total;
		total = 0;
	}
	cout << max;
}