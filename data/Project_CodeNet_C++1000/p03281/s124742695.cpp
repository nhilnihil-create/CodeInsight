#include<bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int main()
{
 fastIO();
 long long n , cnt = 0 , divCnt;
 cin>>n;
 
 for(int i=1; i<=n; i=i+2) //run with odds 
{	
		divCnt=0;
	for(int j=1; j<=i; j++)
	{
		if(i%j == 0)
		{
			divCnt++;
		}
	}
	if(divCnt == 8) // exact 8 divs.
	{
		cnt++;
	}
}

cout<< cnt << endl;

return 0;
}
