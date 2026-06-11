#include <bits/stdc++.h>
using namespace std;
int n,a,b,cost;
vector<int>ans;
int main(){
//	freopen("readin.txt","r",stdin);
	scanf("%d%d%d",&n,&a,&b);
	if(a*1LL*b < n || a + b - 1 > n)return puts("-1"),0;
	for(int i = n - a + 1;i <= n;i++)ans.push_back(i);
	n-=a;
	for(int i = b - 1;i >= 1;i--){
		int t = min(n - i + 1,a);
		for(int j = n - t + 1;j <= n;j++)ans.push_back(j);
		n-=t;
	}
	for(auto i : ans)printf("%d ",i);
}