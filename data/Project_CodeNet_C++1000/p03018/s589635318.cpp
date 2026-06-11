#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int fg[200005],fg2[200005];
int main(int argc, char** argv) {
	string s;
	cin>>s;
	ll p=0,ans=0;
	rep2(i,s.length()-1,0)
	{
		if(s[i]=='B'||(s[i]=='C'&&s[i-1]!='B'))
		{
			p=0;
			continue;
		}
		if(s[i]=='A')
		{
		ans+=p;	
		}
		else
		{
			p++;
			i--;
		}
		
	}
	cout<<ans;
	return 0;
}