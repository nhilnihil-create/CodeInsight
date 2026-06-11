#include<bits/stdc++.h>
using namespace std;

int a[200010];

void fail(){
	cout<<-1<<endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long int ans = 0;
	if(a[1]!=0)	fail();
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>1)	fail();
		if(a[i]==a[i-1]+1)	ans++;
		else	ans+=a[i];
	}
	cout<<ans<<endl;
}
