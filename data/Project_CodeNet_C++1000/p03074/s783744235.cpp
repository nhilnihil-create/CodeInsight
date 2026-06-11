#include<iostream>
using namespace std;
#include<vector>
#include<map>
#define int long long int
int32_t main()
{
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    int answer=0;
    vector<int> v;
    map<int,int> mp1,mp2;
    int count=0;
    int j;
    for(j=0;j<n;j++)
    {
		if(str[j]=='0')
		{
			mp1[j]=count;
			mp2[count]=j;
			count++;
			while(j<n&&str[j]=='0')
			{
				j++;
			}
	    }
	}
    for(j=0;j<n;j++)
    {
		if(str[j]=='0')
		{
			int i=mp1[j];
			auto it=mp2.find(i+k);
			int end;
			if(it==mp2.end())
			  end=n-1;
			else
			  end=it->second-1;
			answer=max(answer,end-j+1);
		}
		else
		{
			int val=0;
			while(j<n&&str[j]=='1')
			{
				val++;
				j++;
			}
			if(j==n)
			{
				answer=max(answer,val);
				break;
			}
			else
			{
				int i=mp1[j];
				auto it=mp2.find(i+k);
				int end;
				if(it==mp2.end())
				   end=n-1;
				else
				   end=it->second-1;
				answer=max(answer,end-j+1+val);
			}
		}
	}
	cout<<answer<<endl;
}
