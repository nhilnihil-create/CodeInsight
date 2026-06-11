#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>

using namespace std;


int main(){
	long long int res=0,n;
	string str[605];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		str[i+n]=str[i];
	}
	
	for(int i=0;i<n;i++)
	{
		bool key=true;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(str[j+i][k]!=str[k+i][j])
				{
					key=false;
					//cout<<i<<" "<<j<<" "<<k;
				}
			}
			
		}
		if(key)
		{
			res+=n;
		}
	}
	cout<<res;
}
