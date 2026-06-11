#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int N,M,X,A[100],count1=0,count2=0;
 cin>>N>>M>>X;
 for(int i=0;i<M;i++)
 {
 	cin>>A[i];
 }
 sort(A,A+M);
 for(int i=X+1;i<N;i++)
 {
 	for(int j=0;j<M;j++)
 	{
 		if(A[j]==i)
 		{
 			count1++;
 		}
 	}
 }
  for(int i=X-1;i>0;i--)
 {
 	for(int j=0;j<M;j++)
 	{
 		if(A[j]==i)
 		{
 			count2++;
 		}
 	}
 }
 int r = min(count1,count2);
 cout<<r<<endl;
}
