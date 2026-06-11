#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack> 
#include<set>
#include<map>
#define gc getchar()
#define ll long long
using namespace std;
#define mem(a,b) memset(a,b,sizeof a)
#define fup(i,a,b) for(int i=a,i##e=b;i<=i##e;++i)
#define hh putchar(10)

int mp[3][103];
void Main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>mp[1][i];
	for(int i=1;i<=n;++i)
		cin>>mp[2][i];
	for(int i=2;i<=n;++i)
		mp[1][i]+=mp[1][i-1];
	for(int i=1;i<=n;++i)
		mp[2][i]+=max(mp[2][i-1],mp[1][i]);
	cout<<mp[2][n];
}


int main(){Main();return 0;}
/*



*/