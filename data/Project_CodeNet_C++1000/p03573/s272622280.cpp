#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n0, n1, n2;
//	string s;
	cin >> n0 >> n1 >> n2;
	if(n0 == n1){
		cout << n2 << endl;
	}else if(n1 == n2){
		cout << n0 << endl;
	}else{
		cout << n1 << endl;
	}
	return 0;
}