#include <bits/stdc++.h>
using namespace std;

int a[100500];

int main(){
	int n, b, c, sum = 0, m = 0, l = 0, k = 0;
	cin >> n >> b >> c;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		if (a[i] <= b){
			m++;
		}
		else if (a[i] > b && a[i] <= c){
			l++;
		}
		else if(a[i] > c){
			k++;
		}
	}
	
	cout << min(m, min(k, l));
    return 0;
}
