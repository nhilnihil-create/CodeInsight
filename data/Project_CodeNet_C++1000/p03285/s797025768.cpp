#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n;
	cin >> n;

	bool res = false;
	for(int i = 0; i <= n; i+=4){
		for(int j = 0; j <= n-i; j+=7){
			if(i+j == n){
				res = true;
				break;
			}
		}
	}

	if(res)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}