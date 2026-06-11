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
ll ls1[Max], ls2[Max],ls3[Max],sum[Max];

int main()
{
	PRE;
	ll n, m;
	cin >> n >> m;
	cout << ((100 * (n - m) + 1900 * m) * pow(2, m));
}