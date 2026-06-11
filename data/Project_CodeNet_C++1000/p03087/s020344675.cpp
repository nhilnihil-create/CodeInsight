#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,q,x,y,AC[100001];
	AC[0]=0;
	string s;
	cin>>n>>q>>s;
	for(int i=1;i<n;i++)
	AC[i]=AC[i-1]+(s[i]=='C'&&s[i-1]=='A');
	while(q--){
		cin>>x>>y;
		cout<<AC[max(x,y)-1]-AC[min(x,y)-1]<<endl;
	}
    return 0;
}
