#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,c,w,h;
	cin>>r>>c>>w>>h;
	c=c-h;
	int cell=c*r;
	int ans=cell-w*c;
	cout<<ans<<endl;

}