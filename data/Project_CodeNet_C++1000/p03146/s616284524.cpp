#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define endl '\n'
using namespace std;
int main()
{
	int s;
	cin>>s;
	vector<int> v;
	vector<int>::iterator it;
	v.push_back(s);
	int ans = 0;
	while(1)
	{
	    ans++;
		if(s%2==0)
			s=s/2;
		else 
		    s = (3*s)+1;
		it = find(v.begin(), v.end(),s);
		if(it==v.end())v.push_back(s);
		else if(it!=v.end()){
			v.push_back(s);
			break;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}