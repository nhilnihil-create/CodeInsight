

#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n,m;
	cin>>n>>m;

	string s[n];

	for(int  i = 0;i<n;i++)
		cin>>s[i];

	for(int  i = 0;i<n;i++)
	{
		 for(int j = 0;j<m;j++)
		 {
		 	if(s[i][j]=='#')
		 		continue;

		 	s[i][j] = '0';
            
            if(i+1 < n && j+1 < m && s[i+1][j+1]=='#')
            	s[i][j]++;

            if(i+1 < n && j < m && s[i+1][j]=='#')
            	s[i][j]++;

            if(i+1 < n && j-1 >=0 && s[i+1][j-1]=='#')
            	s[i][j]++;

            if(i < n && j-1 >=0 && s[i][j-1]=='#')
            	s[i][j]++;

            if(i-1 >= 0  && j-1 >= 0 && s[i-1][j-1]=='#')
            	s[i][j]++;

            if(i-1 >= 0 && j < m && s[i-1][j]=='#')
            	s[i][j]++;

            if(i-1 >= 0 && j+1 < m && s[i-1][j+1]=='#')
            	s[i][j]++;

            if(i < n && j+1 < m && s[i][j+1]=='#')
            	s[i][j]++;

		 }
	}



	for(int  i = 0;i<n;i++)
		cout<<s[i]<<endl;
}