#include<bits/stdc++.h>
using namespace std;
int n,ans;
void dfs(long long num,int f){
	if (num > n)
		return ;
	if (f == 7)
		ans++;
	dfs(num * 10 + 3,f | 1);
	dfs(num * 10 + 5,f | 2);
	dfs(num * 10 + 7,f | 4);	
}
int main(){
	cin >> n;
	dfs(0,0);
	cout << ans << endl;
	return 0;
}