#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	long long int x[50], xs[50], y[50], ys[50];
	int n, k;
	cin >> n >> k;
	int i1,i2,j1,j2,i,l;
	for (i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		xs[i] = x[i]; ys[i] = y[i];
	}
	sort(xs, xs + n);
	sort(ys, ys + n);
	int counter;
	long long int rectangle = 4000000000000000000;
	for (i1 = 0; i1 < n-1; i1++) {
		for (j1 = i1 + 1; j1 < n; j1++) {
			for (i2 = 0; i2 < n - 1; i2++) {
				for (j2 = i2 + 1; j2 < n; j2++) {
					if ((xs[j1] - xs[i1]) * (ys[j2] - ys[i2]) < rectangle) {


						counter = 0;
						for (i = 0; i < n; i++) {
							if ((x[i] >= xs[i1]) && (x[i] <= xs[j1]) && (y[i] >= ys[i2]) && (y[i] <= ys[j2])) {
								counter++;
							}
						}
						if (counter >= k) {
							rectangle = (xs[j1] - xs[i1]) * (ys[j2] - ys[i2]);
						}
					}
				}
			}
		}
	}
	cout << rectangle << endl;
	return 0;

}