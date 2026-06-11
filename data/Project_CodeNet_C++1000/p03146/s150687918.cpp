#include<bits/stdc++.h>
using namespace std;

int d[1000001];
int main()
{
int s,i=1;
cin>>s;
for(;;i++)
if(d[s]){cout<<i<<endl;return 0;}
else
{d[s]=1;
	
	s=(s&1)?3*s+1:(s>>1);
	
}


}

