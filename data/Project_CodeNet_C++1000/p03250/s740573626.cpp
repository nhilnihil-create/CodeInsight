#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<max(a,max(b,c))*9+a+b+c<<endl;
	return 0;
}