#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int size=s1.size()*3,len=s1.size();
    string s=s1+s1+s1;
    int flag;
    if(s1==s2) flag=1;
    else flag=0;
    for(int i=0;i<size;++i)
    {
    	string temp=s.substr(i,len);
    	if(temp==s2){
    		flag=1;break;
		}
	}
    printf("%s\n",flag?"Yes":"No");
}