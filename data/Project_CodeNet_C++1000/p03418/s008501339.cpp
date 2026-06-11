#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int n, k;
	cin >> n >> k;
	ll answer = 0;
	for(int b = k+1; b<= n; b++){
		if(k == 0) answer-- ;
		answer += (n/b)*(b-k);
		int sub = n%b - k + 1;
		if(sub > 0) answer += sub;
	}

	cout << answer << endl;
}
