#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int
int main()
{
	int a,b;
	cin>>a>>b;
	if (a>b)
	cout<<a+a-1;
	else if (a<b)
	cout<<b+b-1;
	else
	cout<<a+a;
}