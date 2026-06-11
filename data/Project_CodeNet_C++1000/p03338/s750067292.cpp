

#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	string s;
	cin>>s;
     int arr[26];int brr[26];
     int m = 0;
	for(int  i = 1;i<n;i++)
	{
         memset(arr,0,sizeof arr);
         memset(brr,0,sizeof brr);

         for(int j = 0;j<i;j++)
         	arr[(s[j]-'a')] = 1;
         for(int j = i;j<n;j++)
         	brr[(s[j]-'a')] = 1;

         int tot = 0;

         for(int  i = 0;i<26;i++)
         	if(arr[i]==1 && brr[i]==1)
         		tot++;

          m  = max(m,tot);
	}
	cout<<m<<endl;
}