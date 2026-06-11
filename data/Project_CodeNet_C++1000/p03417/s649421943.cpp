#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	ll n, m;
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << 1 << endl;
	}else if(n == 1 || m == 1){
		ll answer = n*m -2;
		if(answer < 0) answer = 0;
		cout << answer << endl;
	}else{
		ll answer = n*m - (n+m)*2 + 4;
		cout << answer << endl;
	}

}
