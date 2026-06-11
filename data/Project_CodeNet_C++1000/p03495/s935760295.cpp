#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;

struct node
{
	node() { a = 0;b = 0; }
	int a, b;
};
node lst[Max];
bool compare(node a, node b)
{
	if (a.b < b.b)return true;
	return false;
}

int main()
{
	PRE;
	int n, k;
	cin >> n >> k;
	int sum = 0;
	map<int, int> ma;
	int t;
	for (int i = 1;i <= n;i++)
	{
		cin >> t;
		if (ma[t] == 0) sum++;
		ma[t]++;
	}
	int g = 0;
	for (auto i = ma.begin();i != ma.end();i++)
	{
		lst[++g].a = i->first;
		lst[g].b = i->second;
	}
	if (sum <= k)cout << 0;
	else
	{
		sort(lst + 1, lst + 1 + g,compare);
		int ans = 0, f = 0;
		for (int i = 1;i <= g;i++)
		{
				ans += (lst[i].b) ;
				f++;
			if (f == sum - k)break;
		}
		cout << ans;
	}

}