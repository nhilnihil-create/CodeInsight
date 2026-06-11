#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[101],b[101];
 cin>>n;
 for(int i=0;i<n;i++) cin>>a[i];
 for(int i=0;i<n;i++) cin>>b[i];
 int t=n,ans,chek=0,maxx=0;
	while(t--){
		ans=0;
	 for(int i=0;i<=chek;i++) ans+=a[i];
		for(int i=chek;i<n;i++) ans+=b[i];
		maxx=max(maxx,ans);
  chek++;
	}
 cout<<maxx;
}