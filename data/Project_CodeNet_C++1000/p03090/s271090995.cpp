#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (int)(n); i++)
#define rep2(i,x,n) for(int i = (int)x; i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define repitr(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){

	int n;
	cin >> n;
	vector<pair<int, int>> vp;
	int fp;
	if(n % 2 == 1) fp = n;
	else fp = n + 1;
	rep2(i, 1, n){
		rep2(j, i+1, n+1){
			if(i+j != fp) vp.push_back(make_pair(i, j));
		}
	}
	cout << vp.size() << endl;
	for(auto p : vp){
		cout << p.first << " " << p.second << endl;
	}
	return 0;
	
}