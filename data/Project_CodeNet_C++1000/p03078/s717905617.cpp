#include<iostream>
#include<algorithm>
using namespace std;
long long int a[1000], b[1000], c[1000], d[1000000],dd[1000000],e[3000000];

int main() {


	int x, y, z, k;
	cin >> x >> y >> z >> k;
	int i,j,l;
	for (i = 0; i < x; i++) {
		cin >> a[i];
	}
	for (i = 0; i < y; i++) {
		cin >> b[i];
	}
	for (i = 0; i < z; i++) {
		cin >> c[i];
	}
	l = 0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			d[l] = a[i] + b[j];
			l++;
		}
	}
	sort(d, d + x * y);
    //for(i = 0;i<x*y;i++){
    //  cout << d[i] << ' ';
    //}
  //cout << endl;
	for (i = 0; i < k; i++) {
		if (i >= x * y)break;
		dd[i] = d[x * y - i - 1];
	}
	int maxd;
	if (k < x * y) {
		sort(dd, dd + k);
		maxd = k;
	}
	else {
		sort(dd, dd + x * y);
		maxd = x * y;
	}
  //for(i=0;i<maxd;i++){
  //  cout << dd[i] << ' ';
  //}cout << endl;
	l = 0;
	for (i = 0; i < maxd; i++) {
		for (j = 0; j < z; j++) {
			e[l] = dd[i] + c[j];
          l++;
		}
	}
	sort(e, e + maxd * z);
  //for(i=0;i<maxd*z;i++){
  //  cout << e[i] << ' ';
  //}cout << endl;
	for (i = 0; i < k; i++) {
		cout << e[maxd * z - 1 - i] << endl;
	}
	return 0;


}