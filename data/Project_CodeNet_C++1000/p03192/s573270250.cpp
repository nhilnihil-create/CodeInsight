#include<bits/stdc++.h>
using namespace std;
int main()
{
	string c;
	int cnt=0;
    cin>>c;
    int l=c.size();
    for(int i=0;i<l;i++) 
	{
		if(c[i]=='2') 
		{
			cnt++;
		}
	}
    cout<<cnt;
    return 0;
} 