#include"iostream"
using namespace std;
int main()
{
	int n,m;cin>>n>>m;
	int ans=1900*m+100*(n-m);ans*=(1<<m);
	cout<<ans;
}
