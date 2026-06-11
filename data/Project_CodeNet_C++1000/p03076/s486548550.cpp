#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	vector<P> T;
	rep(i,5){
		int a, b;
		cin >> b;
		if(b%10==0) a = 0;
		else a = 10 -b % 10;

		T.push_back(make_pair(a,b));
	}
	sort(T.begin(),T.end());
	int ans = 0;
	rep(i,4) ans += T[i].first + T[i].second;
	ans += T[4].second;
	cout << ans << endl;	
}











