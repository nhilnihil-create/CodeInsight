#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
int n,A,B,C;
vector<int> l;

int dfs(int dep, int a, int b, int c){
	if(dep==n){
		int ret = (min(min(a,b),c) > 0)? abs(a-A)+abs(b-B)+abs(c-C)-30: INF;
		return ret;
	}

	int ret0 = dfs(dep+1, a, b, c);
	int ret1 = dfs(dep+1, a+l[dep], b, c)+10;
	int ret2 = dfs(dep+1, a, b+l[dep], c)+10;
	int ret3 = dfs(dep+1, a, b, c+l[dep])+10;

	return min(min(ret0,ret1),min(ret2,ret3));
}

int main(){
	cin >> n >> A >> B >> C;
	for(int i=0; i<n; i++){
		int len;
		cin >> len;
		l.push_back(len);
	}
	
	cout << dfs(0,0,0,0) << endl;
	return 0;
}