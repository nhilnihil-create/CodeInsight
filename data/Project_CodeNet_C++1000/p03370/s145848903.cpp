#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int N,X,m[101],s=0,M=1111101110;
 cin>>N>>X;
 for(int i=0;i<N;i++)
 {
 	cin>>m[i];
 	s=s+m[i];
 	if(m[i]<M)
 	{
 		M = m[i];
 	}
 }
 int k = N + (X-s)/M;
 cout<<k<<endl;
   

 		

}
 