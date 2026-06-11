#include <bits/stdc++.h> 
using namespace std;

vector<int> A[21][21];

int kose(int n)
{
if(n==1){return 2;}
else if(n==2){return 2;}
else if(n%2==1){return kose(n-1);}
else{return kose(n/2)+1;}			
}



void graf(int n)
{
if(n==1){A[1][2].push_back(0); return;}
else if(n==2){A[1][2].push_back(0); A[1][2].push_back(1); return;}	
else if(n%2==1){ graf(n-1); A[1][kose(n)].push_back(n-1);   }	
else{
graf(n/2);
for(int i=1;i<=20;i++)
{
for(int j=1;j<=20;j++)
{
for(int k=0;k<A[i][j].size();k++){A[i][j][k]*=2;}	
}
		
			
}

A[kose(n)-1][kose(n)].push_back(0); A[kose(n)-1][kose(n)].push_back(1);

}	

	
	

}


int main()
{ int n,sum=0; scanf("%d",&n);
graf(n);
for(int i=1;i<=20;i++)
{
for(int j=1;j<=20;j++)
{
	sum+= A[i][j].size();
	//printf("%d %d %d\n",i,j,A[i][j].size());
}
		
			
}
printf("%d %d\n",kose(n),sum);

for(int i=1;i<=20;i++)
{
for(int j=1;j<21;j++)
{
for(int k=0;k<A[i][j].size();k++){printf("%d %d %d\n",i,j,A[i][j][k]);}	
}
		
			
}
//printf("%d",n);
	

return 0;
}