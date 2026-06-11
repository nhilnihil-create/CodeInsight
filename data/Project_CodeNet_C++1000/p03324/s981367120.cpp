#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int a,b;
	cin>>a>>b;
	switch(a){
		case 0:if(b<100)cout<<b;else cout<<101;break;
		case 1:if(b<100)cout<<b<<"00";else cout<<10100;break;
		case 2:if(b<100)cout<<b<<"0000";else cout<<1010000;break; 
	}
    return 0;
}
