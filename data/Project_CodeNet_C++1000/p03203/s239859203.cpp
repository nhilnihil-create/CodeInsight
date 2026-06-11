#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int h,w,n;
int x[1<<18],y[1<<18];
pair<int,int>X[1<<18];
main()
{
	cin>>h>>w>>n;
	int ans=h;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		X[i]=make_pair(x[i],y[i]);
	}
	sort(X,X+n);
	int nowx=1,nowy=1;
	for(int i=0;i<n;i++)
	{
		while(nowx+1<X[i].first)nowx++,nowy++;
		if(nowx>=X[i].first)continue;
		if(nowx+1==X[i].first&&nowy>=X[i].second)
		{
			cout<<nowx<<endl;
			return 0;
		}
		else if(nowx+1==X[i].first&&nowy+1==X[i].second)nowx++;
	}
	cout<<ans<<endl;
}
