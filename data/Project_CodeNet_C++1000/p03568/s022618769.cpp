#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;cin >> N;
	int odd = 0, even = 0;

	rep(i,N){
		int tmp; cin >> tmp;
		if(tmp%2==0) ++even;
		else ++odd;
	}
	int ans = 0;
	int tmp = 1;
	rep(i,N) tmp *= 3;
	ans += tmp;
	tmp = 1;
	rep(i,even) tmp *= 2;
	ans -= tmp;
	cout << ans << endl;




}



