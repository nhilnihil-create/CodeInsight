#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

vector<int> ans;

int main(void)
{
	int n;
	scanf("%d",&n);
	
	while(n)
	{
		int now = n%-2;
		n/=-2;
		if(now < 0) ++n, now+=2;
		ans.push_back(now);
	}
	
	reverse(ans.begin(),ans.end());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d",ans[i]);
	if(!ans.size()) putchar('0');
	putchar('\n');
	return 0;
}