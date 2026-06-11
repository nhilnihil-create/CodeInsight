#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	 int n,m,c,k;
	 cin>>n>>m>>c;
	 int cnt = 0;
	 vector<int>b(m);
	 for(int  i = 0;i<m;i++)cin>>b[i];

	 for(int  i = 0;i<n;i++)
	 {
          int sum = c;
          for(int  i = 0;i<m;i++)
          {
          	 cin>>k;
          	 sum+=(b[i]*k);
          }

          if(sum >0)
          	cnt++;
	 }
	 cout<<cnt<<endl;	
}