#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int mcc = n/4 +1;
	int mdc = n/7 +1;
	for(int i = 0;i < mcc;i++){
		for(int j = 0;j < mdc;j++){
			if(i*4 + j*7 == n){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}