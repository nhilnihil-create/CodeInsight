#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (int)(n); i++)
#define rep2(i,x,n) for(int i = (int)x; i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define repitr(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n, in;
	cin >> n;
	vector<int> p(n);
	rep(i, n){
		cin >> in;
		in--;
		p.at(in) = i;
	}
	int ans = 0, temp = -1;
	rep(i, n){
		if(i == n - 1 || p.at(i) > p.at(i+1)){
			ans = max(ans, i - temp);
			temp = i;
		}
	}
	cout << n - ans << endl;
	return 0;
}
