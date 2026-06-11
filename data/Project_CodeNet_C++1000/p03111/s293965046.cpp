#include <bits/stdc++.h>
using namespace std;
int n,A,B,C;

int dfs(vector<int> l,int cur,int a,int b, int c){
	if(cur == n)
	{
		if(min({a,b,c}) > 0)
		{
			return abs(a-A)+abs(b-B)+abs(c-C)-30;
		}
		else
		{
			return pow(10,9);
		}
	}
	int ret0 = dfs(l,cur+1,a,b,c);
	int ret1 = dfs(l,cur+1,a+l.at(cur),b,c)+10;
	int ret2 = dfs(l,cur+1,a,b+l.at(cur),c)+10;
	int ret3 = dfs(l,cur+1,a,b,c+l.at(cur))+10;
	return min({ret0,ret1,ret2,ret3});
}

int main() {
	cin >> n >> A >> B >> C;
	vector<int> l(n);
	for(int i=0;i<n;i++)
	{
		cin >> l.at(i);
	}
	cout << dfs(l,0,0,0,0) << endl;
	return 0;
}
