#include<bits/stdc++.h>
using namespace std;
int main()
{
   string x;

	cin>>x;
 /*  for(int i=0;i<4;i++)
   {
       x=a%10;
       a/=a;
       arr[i]=x;
   }*/
if((x[0]==x[1]&&x[1]==x[2]&&x[2]==x[3])||(x[1]==x[2]&&x[2]==x[3])||(x[0]==x[1]&&x[1]==x[2]))
    cout<<"Yes";
else
    cout<<"No";
	return 0;
	}



