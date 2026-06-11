#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
main(){
	int n;
	cin>>n;
	int l=0,r=n;
	cout<<0<<endl;
	string pre,now;
	cin>>pre;
	int P=l;
	r(i,30){
		int mid=(l+r)/2;
		cout<<mid<<endl;
		cin>>now;
		if(now=="Vacant")break;
		if(P<mid&&(abs(P-mid)%2==0&&now==pre||abs(P-mid)%2==1&&now!=pre)||
		   P>mid&&(abs(P-mid)%2==1&&now==pre||abs(P-mid)%2==0&&now!=pre)
			){
			l=mid+1;
		}
		else{
			r=mid;
		}
		pre=now;
		P=mid;
	}
exit(0);
}
