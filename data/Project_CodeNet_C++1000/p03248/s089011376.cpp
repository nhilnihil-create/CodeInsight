#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define rep(i,a,b) for(int i=a;i<=b;i++)
void add(int u,int v)
{
	if(u>v)swap(u,v);
	printf("%d %d\n",u,v);
	
}
int main(int argc, char** argv) {

	string s;
	cin>>s;
	int tot=1,now=1;
	if(s[0]!='1'||s[s.length()-1]=='1')
	{
		puts("-1");
		return 0;
	}
	rep(i,0,s.length()-2)
	{
		if(s[i]=='1'&&s[s.length()-i-2]!='1')
		{
			puts("-1");
			return 0;
		} 
		
	}
	rep(i,0,s.length()-2)
	{
		if(s[i]=='0')
		{
			add(now,++tot);
		}
		else
		{
			add(++tot,now);
			now=tot;
		}
	}
	return 0;
}