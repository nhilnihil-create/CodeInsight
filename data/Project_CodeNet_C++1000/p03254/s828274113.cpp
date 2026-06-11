#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long x;
	cin >> n >> x;
	vector<long> a(n);
	for (int i=0; i<n; i++){
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	int num=0;
	long sum=0;
	for(int i=0; i<n; i++){
		sum += a.at(i);
	}
	if(sum == x) {
		num = n;
	}
	if(sum != x) {
		long newsum=0;
		for(int i=0; i<n-1; i++){
			newsum += a.at(i);
			if(newsum > x) {
				break;
			}
			if(newsum <= x) {
				num++;
			}
		}
	}
	cout << num << endl;
}

