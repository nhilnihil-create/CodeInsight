#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a,b,x;
	cin>>a>>b>>x;
	if(x<a)cout<<"NO"<<endl;
	else if(a<=x&&x<=a+b)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}