#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7,MAX = 1e5;

int main()
{
	ll N;
	cin >> N;
	//4 = N(1/h+1/n+1/w)
	//4hnw = Nnw+Nhw+Nhn
	//4hnw -Nnw - Nhn = Nhw
	//n(4hw-Nw-Nh)=Nhw
	//n=Nhw/(4hw-Nw-Nh)

	for(ll h = 1;h<=3500;h++)
	{
		for(ll w = h;w<=3500;w++)
		{
			if((4*h*w-N*w-N*h)==0)continue;
			if(h==3498&&w==3498)cout<<(N*h*w)%(4*h*w-N*w-N*h)<<endl;
			if((N*h*w)%(4*h*w-N*w-N*h)==0&&(N*h*w)/(4*h*w-N*w-N*h)>0)
			{
				cout<<h<<' '<<w<<' '<<N*h*w/(4*h*w-N*w-N*h)<<endl;
				return 0;
			}
		}
	}
	return 0;
}