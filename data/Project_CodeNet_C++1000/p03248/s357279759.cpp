#include<bits/stdc++.h>
using namespace std;
int l,t=1;
string st;
int main()
{
	cin>>st;
	l=st.size();
	st=' '+st;
	if(st[1]=='0') 
	{
		cout<<-1;
		return 0;
	}
    if(st[l]=='1') 
	{
		cout<<-1;
		return 0;
	}
    for(int i=1;i<l;i++)
    {
        if(st[i]!=st[l-i]) 
		{
			cout<<-1;
			return 0;
		}
    }
    for(int i=1;i<l;i++)
	{
        cout<<i+1<<" "<<t<<endl;
        if(st[i]=='1') t=i+1;
    }
    return 0;
}