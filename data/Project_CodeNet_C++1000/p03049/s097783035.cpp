#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,len,x=0;
	int nA=0,nB=0,nAB=0;
	cin>>n;
	while(n--)
	{
		string arr;
		cin>>arr;
		len=arr.size();
		for(int i=0;i<len-1;i++)
		{
			if(arr[i]=='A'&&arr[i+1]=='B')
				nAB++;
		}
		if(arr[0]=='B')
			nB++;
		if(arr[len-1]=='A')
			nA++;
		if(arr[0]=='B'&&arr[len-1]!='A'||arr[0]!='B'&&arr[len-1]=='A')
			x=1;
	}
	if(x==0&&nA>0)
		nA--;
	cout<<nAB+min(nA,nB);
	return 0;
}