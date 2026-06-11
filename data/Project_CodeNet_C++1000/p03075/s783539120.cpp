#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main(){

	int k;
	vector<int> v(5);
	rep(i,5) scanf("%d", &v[i]);
	scanf("%d", &k);
	
	rep(i,5){
		rep(j,5){
			if (abs(v[i]-v[j]) > k){
				cout <<":(\n";
				return 0;
			} 
		}
	}
	cout << "Yay!\n";
	return 0;
}
