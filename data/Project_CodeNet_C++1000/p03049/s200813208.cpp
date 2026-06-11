#include<iostream>
using namespace std;
#include<vector>
#define int long long int
int32_t main()
{
     int n;
     cin>>n;
     int answer=0;
     int a=0,b=0,c=0;
     vector<string> v1,v2;
     for(int j=0;j<n;j++)
     {
		 string str;
		 cin>>str;
		 int l=str.size();
		 int i;
		 for(i=0;i<l-1;i++)
		 {
			 if(str[i]=='A'&&str[i+1]=='B')
			    answer++;
		 }
		 if(str[l-1]=='A'&&str[0]!='B')
		 {
			a++;
		 }
		 if(str[0]=='B'&&str[l-1]!='A')
		 {
			 b++;
		 }
		 if(str[0]=='B'&&str[l-1]=='A')
		 {
			 c++;
		 }
	 }
     if(c==0)
     {
		 answer+=min(a,b);
	 }
	 else
	 {
		 if(a+b>0)
		 {
			 answer+=min(a,b)+c;
		 }
		 else
		 {
			 answer+=c-1;
		 }
	 }
	 cout<<answer<<endl;
}
