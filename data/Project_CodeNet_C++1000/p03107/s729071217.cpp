#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

int main(){
	string s;
	cin >> s;
	vector<char> cube;
	
	ll ans = 0;
	for(char c : s){
		if(cube.size() == 0 || cube.back() == c){
			cube.push_back(c);
		}
		else{
			cube.pop_back();
			ans += 2;
		}
	}
	
	cout << ans << endl;
	return 0;
}

