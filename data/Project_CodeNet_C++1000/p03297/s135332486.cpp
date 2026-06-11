/*******************
Problem:
Author:CXY1999
Status:Coding
*******************/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<vector>
#include<set>
#include<cmath>
#include<queue>
#include<algorithm>
#define push_back pb
#define begin BG
#define end ED
typedef long long LL;
using namespace std;
int T;
LL a,b,c,d;
LL llgcd(LL a,LL b){return (b==0)?a:llgcd(b,a%b);}
 
int main()
{
	//freopen("a.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		if(a<b){puts("No");continue;}
		if(d<b){puts("No");continue;}
		if(c>=b){puts("Yes");continue;}
		a%=b;
		d%=b;
		//Ä¤bÒâÒåÏÂ
		LL left=c-a;
		LL right=b-a;
		//[c+1,b-1]
		LL r=llgcd(b,d);
		if(left<0){puts("No");continue;}
		else{
			if((d==0)||((left/r+1)*r>=right)){puts("Yes");continue;}
			else {puts("No");continue;}
		}
	}
}