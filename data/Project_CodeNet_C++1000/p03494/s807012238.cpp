#include<iostream>
using namespace std;

int a[200], n, r, cntr, mn = 40;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cntr = 0;
		r = a[i] % 2;
		while(r == 0){
			cntr++;
			a[i] = a[i] / 2;
			r = a[i] % 2; 
		}
		if (mn > cntr){ mn = cntr; }
	}
	cout << mn << endl;
}
