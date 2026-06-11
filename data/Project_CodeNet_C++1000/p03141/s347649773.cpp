#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

struct food
{
	ll a,b,id,div;
};

bool cmp(food a,food b)
{
	if(a.div!=b.div)return a.div>b.div;
	if(a.a!=b.a)return a.a>b.a;
	return a.b > b.b;
}

int main()
{
	int n;
	cin >> n;
	vector<food> tkhs(n),aok(n);
	vector<ll> ttoi(n),atoi(n);

	ll ans = 0;
	for(int i =0;i<n;i++)
	{
		ll a,b;
		cin >> a >> b;
		tkhs[i].a = a;
		tkhs[i].b = b;
		tkhs[i].id = i;
		tkhs[i].div = a+b;
		ans -= b;
	}
	sort(tkhs.begin(),tkhs.end(),cmp);
	//for(int i = 0;i<n;i++){cout<<tkhs[i].a<<';'<<tkhs[i].b<<endl;}
	//cout<<ans<<endl;
	for(int i = 0;i<n;i++)
	{
		if(i%2==0)ans += tkhs[i].div;
	}
	cout<<ans<<endl;
	return 0;
}