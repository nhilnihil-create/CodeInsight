#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n, k;
	cin >> n >> k;
	if(n%k == 0){
		cout << 0 << endl;
	}else{
		cout << 1 << endl;
	}
	return 0;
}