#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

const int INF=100000008;

int main()
{
	int n;
	cin >> n;
	int T=0;
	vector<int> begi(n+2);
	vector<int> en(n+2);
	begi[0]=0;
	en[0]=0;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		begi[i]=T;
		T+=t;
		en[i]=T;
	}
	begi[n+1]=T;
	en[n+1]=T;
	vector<int> v(n+2);
	v[0]=0;
	v[n+1]=0;
	for(int i=1;i<=n;i++)
		cin >> v[i];

	vector<double> velo(2*T+1,INF);

	for(int i=0;i<2*T+1;i++)
	{
		double now=i*0.5;
		for(int j=0;j<n+2;j++)
		{
			double lim;
			if(now<begi[j])lim=v[j]+begi[j]-now;
			else if(en[j]<now)lim=v[j]+now-en[j];
			else lim=v[j];
			if(velo[i]>lim)velo[i]=lim;
		}
	}

	double ans=0;

	for(int i=0;i<2*T;i++)
		ans+=(0.5*(velo[i]+velo[i+1])/2);

	cout << fixed << setprecision(13) << ans << endl;
}



