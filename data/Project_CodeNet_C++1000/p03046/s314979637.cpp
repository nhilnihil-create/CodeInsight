#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,k,i,j,cur;
	cin >> m >> k;
	cur=1;
	for(i=0; i<m; i++){
		cur*=2;
	}
	
	if(m==0 && k==0){
		cout << "0 0" << endl;
	}else if(m==1 && k==0){
		cout << "0 0 1 1" << endl;
	}else if(m<=1 || cur<=k){
		cout << -1 << endl;
	}else{
		for(i=0; i<cur; i++){
			if(i==k){
				continue;
			}else{
				cout << i << ' ';
			}
		}
		cout << k << ' ';
		for(i=cur-1; i>=0; i--){
			if(i==k){
				continue;
			}else{
				cout << i << ' ';
			}
		}
		cout << k << endl;
	}
	
}