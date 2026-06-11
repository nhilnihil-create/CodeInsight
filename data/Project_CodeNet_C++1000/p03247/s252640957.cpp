#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n, x[1005], y[1005];
vector<int> vt;
int main() {
	int i, j;
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>x[i]>>y[i];
		if((int)abs(x[i]) + (int)abs(y[i]) & 1 ^ (int)abs(x[0]) + (int)abs(y[0]) & 1) {
			cout<<-1; return 0;
		}
	}
	for(i=30; i>=0; i--) vt.push_back(1<<i);
	if((int)abs(x[0]) + (int)abs(y[0]) & 1 ^ 1) vt.push_back(1);
	cout<<vt.size()<<endl;
	for(i=0; i<vt.size(); i++) cout<<vt[i]<<' ';
	puts("");
	for(i=0; i<n; i++, puts("")) for(j=0; j<vt.size(); j++) {
		if((int)abs(x[i]) > (int)abs(y[i])) {
			if(x[i] > 0) putchar('R'), x[i] -= vt[j];
			else putchar('L'), x[i] += vt[j];
		} else {
			if(y[i] > 0) putchar('U'), y[i] -= vt[j];
			else putchar('D'), y[i] += vt[j];
		}
	}
	return 0;
}