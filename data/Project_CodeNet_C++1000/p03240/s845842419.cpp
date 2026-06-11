#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n),y(n),h(n);
	for(int i=0;i<n;i++)
	{
		cin >> x.at(i) >> y.at(i) >> h.at(i);
	}
	int kx,ky,kh;
	for(int i=0;i<101;i++)
	{
		int f=0;
		for(int j=0;j<101;j++)
		{
			int hh=0;
			for(int k=0;k<n;k++)
			{
				if(h.at(k)==0)
				{
					continue;
				}
				int h1=h.at(k)+abs(i-x.at(k))+abs(j-y.at(k));
				kh=h1;
				kx=i;
				ky=j;				
				if(k>0)
				{
					if(h1==hh)
					{
						f=1;
					}
					else
					{
						f=0;
					}
					if(f==0)
					{
						break;
					}
				}
				hh = h1;
			}
			for(int k=0;k<n;k++)
			{
				int mh=max(0,kh-abs(kx-x.at(k))-abs(ky-y.at(k)));
				if(h.at(k)!=mh)
				{
					f=-1;
				}
			}
			if(f>-1)
			{
				f=1;
			}
			if(f==1)
			{
				break;
			}
		}
		if(f==1)
		{
			break;
		}
	}
	cout << kx << ' ' << ky << ' ' << kh << endl;
	return 0;
}
