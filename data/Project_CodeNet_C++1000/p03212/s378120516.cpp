#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;

ll dfs(ll x, ll three, ll five, ll seven){
	if(n<x) return 0;
	ll ret = 0;
	if(0<three && 0<five && 0<seven) ret++;
	ret += dfs(x*10+3, three+1, five, seven);
	ret += dfs(x*10+5, three, five+1, seven);
	ret += dfs(x*10+7, three, five, seven+1);

	return ret;
}


int main(){
	cin >> n;
	cout << dfs(0,0,0,0) << endl;

	return 0;
}