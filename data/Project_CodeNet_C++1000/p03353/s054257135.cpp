#include "bits/stdc++.h"
//complication terminated
using namespace std;
int main()
{
	string s;
	cin>>s;
	int standing;
	cin>>standing;//第几个子字符串 
	set<string> ans;//子字符串 
	for(int i=0;i<s.size();i++)
	{
		string cnt = "";//初始化 
		for(int j = i;j<i+standing;j++)//最长能length 
		{
			if(j<s.size())//
				cnt+=s[j],ans.insert(cnt);//把字符串存起来 
//			cout<<"the substring="<<cnt<<endl;
		} 
	}
	int run = 0;
	for(set<string>::iterator it = ans.begin();it!=ans.end();it++,run++)
	{
		if(run == standing-1)//如果到了第standing个，输出。 
		{
			cout<<*it<<endl;
			break;
		}
	}
	return 0;
}