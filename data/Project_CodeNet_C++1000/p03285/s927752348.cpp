#include<bits/stdc++.h>
using namespace std;
void Yes(){
	cout<<"Yes\n";
	exit(0);
}
void No(){
	cout<<"No\n";
	exit(0);
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin>>n;
	if(n<4||(n>4&&n<7))No();
	if(n%4==0||n%7==0)Yes();
	for(int i=1;i<=n/4+1;i++){
		int j=n-i*4;
		if(j%7)continue;
		else Yes();
	}
	No();
    return 0;
}
