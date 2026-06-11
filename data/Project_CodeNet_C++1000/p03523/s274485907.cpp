//#include<bits/stdc++.h>
#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	string s1;
	cin >> s1;
	
	string s2 = "AKIHABARA";
	int idx = 0;
	int f = 1;
	
	int take[100]={0};
	if (s2.size() < s1.size()) f = 0;
	
	
	
	for (int i = 0; i < s1.size(); i++)
	{
		if (idx >= s2.size())
		{
			f = 0;
			break;
		}
		
		while (s1[i]!=s2[idx])
		{
			idx++;
			if (idx >= s2.size())
			{
				f = 0;
				break;
			}
		}
		take[idx]=1;
		idx++;
	}
	
	for (int i = 0; i < s2.size(); i++)
	{
		if (!take[i] && s2[i]!='A') f = 0;
	}
	
	if (f)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}