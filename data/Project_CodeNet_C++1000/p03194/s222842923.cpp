#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
typedef long long lint;
using namespace std;

template<typename T> 
void factP(map<T,T> &m,T n)
{
	T x=n;
	for(T i=2;i*i<=n;i++)
	{
		while(x%i==0)
		{
			m[i]++;
			x/=i;
		}
	}
	return;
}

int main()
{
	lint N,P;
	map<lint,lint> m;
	lint ans=1;
	
	cin >> N >> P;

	if(N==1)
	{
		cout << P << endl;
		return 0;
	}
	if(P==1)
	{
		cout << 1 << endl;
		return 0;
	}
	
	factP(m,P);
	
	for(auto&& i:m)
	{
		if(i.second<N)continue;
		ans*=pow(i.first,i.second/N);
	}
	cout << ans << endl;
	return 0;
}