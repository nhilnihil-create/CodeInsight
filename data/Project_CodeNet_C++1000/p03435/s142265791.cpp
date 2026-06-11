 #include<bits/stdc++.h>
 using namespace std;
 
 
 int main()
 {
 	int g[4][4];
 	
 	for(int i=1;i<=3;i++)
 	{
 	   for(int j=1;j<=3;j++)
		{
			cin>>g[i][j];
		}	
	}
	
	//for(int i=0;i<=100;i++)
	{
		int a1=0;	
		int b1=(g[1][1])-a1;
		int a2=(g[1][2]-b1);
		int a3=g[1][3]-b1;		
		int b2=(g[2][1])-a1;
		int b3=g[3][1]-a1;
		int ok=0;
		if(g[1][1]!=a1+b1)ok=1;
		if(g[1][2]!=a2+b1)ok=1;
		if(g[1][3]!=a3+b1)ok=1;
		if(g[2][1]!=b2+a1)ok=1;
		if(g[2][2]!=b2+a2)ok=1;
		if(g[2][3]!=b2+a3)ok=1;
		if(g[3][1]!=b3+a1)ok=1;
		if(g[3][2]!=b3+a2)ok=1;
		if(g[3][3]!=b3+a3)ok=1;
		if(ok==0)
		{
			cout<<"Yes\n";
			return 0;
		}
		
	}
	cout<<"No\n";
 }