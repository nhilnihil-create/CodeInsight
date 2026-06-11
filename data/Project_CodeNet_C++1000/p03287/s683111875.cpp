#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, m;
	cin >> n >> m;
	map<int, int> mod;
	ll sum = 0;
	int it = 0;
	rep(j, n){
		int i;
		cin >> i;
		if(j == 0){
			mod[i%m]++;
		}else{
			it -= i%m;
			if(it < 0) it += m;
			mod[(it+i%m)%m]++;
		}
		sum += mod[it];
	}
	cout << sum << endl;
	return 0;
}