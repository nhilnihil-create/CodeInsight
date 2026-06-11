#include<bits/stdc++.h>
using namespace std;
int main()
{   char c[]={'3','5','7'};
	 int n;
	 cin>>n;
	 queue<string>q;
	 q.push("3");
	 q.push("5");
	 q.push("7");
	 int on=3,nn=0,ans=0,flag=0;
	  while(1)
    {
    	for(int i=1;i<=on;i++)
    	{
    		 string t=q.front();
    		 q.pop();
    		 for(int j=0;j<3;j++)
    		 {
    		 	string tt=t+c[j];
    		
    		 	int num3=0,num5=0,num7=0;
    		 	for(int k=0;k<tt.length();k++)
    		 	{
    		 		if(tt[k]=='3')num3++;
    		 		else if(tt[k]=='5')num5++;
    		 		else if(tt[k]=='7')num7++;
    		 		
				 }
				 
    		 	stringstream ss;
    		 	int x;
    		 	ss<<tt;
    		 	ss>>x;
    		 	q.push(tt);
    		 	nn++;
    		 	if(x<=n){
    		 		if((num3&&num5&&num7))
    		 		ans++;
				 }
				 else
				 {
				 	flag=1;
				 	break;
				 }
			 }
			 if(flag)break;
		}
		if(flag)break;
		on=nn;
		nn=0;
	}
	printf("%d",ans);
 } 