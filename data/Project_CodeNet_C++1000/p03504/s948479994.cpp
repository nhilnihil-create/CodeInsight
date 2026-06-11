#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,c;
	cin>>n>>c;
	vector<tuple<int,int,int>>times;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		times.push_back({a,b,c});
	}
	sort(times.begin(),times.end());

	vector<tuple<int,int,int>>recorders;
	recorders.push_back(times[0]);
	get<0>(recorders[0])-=0.5;
	for(int i=1;i<n;i++)
	{
		bool flag=false;
		for(int j=0;j<recorders.size();j++)
		{
			
			if(get<2>(recorders[j])==get<2>(times[i])){
				get<1>(recorders[j])=get<1>(times[i]);
				flag=true;
				break;
			}
			else if(get<0>(times[i])>=0.5+get<1>(recorders[j])){
				get<1>(recorders[j])=get<1>(times[i]);
				get<2>(recorders[j])=get<2>(times[i]);
				flag=true;
				break;
			}
		}
		if(flag==false)
			recorders.push_back({get<0>(times[i])-0.5,get<1>(times[i]),get<2>(times[i])});

	}
	cout<<recorders.size()<<"\n";
//	for(int i=0;i<times.size();i++)
//		cout<<get<0>(times[i])<<" "<<get<1>(times[i])<<" "<<get<2>(times[i])<<"\n";
}