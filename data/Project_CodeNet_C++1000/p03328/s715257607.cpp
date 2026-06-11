#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin>>a>>b;
	int sum=0;
	map<int,int> m;
	for(int i=1;i<=999;i++)
	{
	    sum+=i;
	    if(sum-a>0)
	    {
	        m[sum-a]++;
	    }
	}
	for(int i=999;i>=1;i--)
	{
	    int sum1 = (i*(i+1))/2;
	    if(m[sum1-b]>0)
	    {
	        cout<<sum1-b<<endl;
	        break;
	    }
	}
	return 0;
}
