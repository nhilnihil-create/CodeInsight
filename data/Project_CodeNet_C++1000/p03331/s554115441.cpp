#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> sum(n-1);
	for(int i=1; i<n; i++){
		int suma=0;
		int sumb=0;
		int c=i;
		int d=n-c;
		while (c>0){
			suma += c%10;
			c /=10;
		}
		while (d>0){
			sumb += d%10;
			d /=10;
		}
		sum.at(i-1)=suma+sumb;
	}
	sort(sum.begin(), sum.end());
	cout << sum.at(0) << endl;
}
