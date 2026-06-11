#include <iostream>
using namespace std;

int main()

{
	ios::sync_with_stdio(false);
	int a,b,c;
	cin>>a>>b>>c;
	int ans=b;
	a+=b;
	ans+=min(a+1,c);
	cout<<ans<<endl;
	return 0;
}