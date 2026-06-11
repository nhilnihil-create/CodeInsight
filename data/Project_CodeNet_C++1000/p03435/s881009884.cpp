#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3][3];
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>a[i][j];
	for(int a0=0;a0<=100;a0++)
	{
		int b0=a[0][0]-a0;
		int b1=a[0][1]-a0;
		int b2=a[0][2]-a0;
		int a1=a[1][0]-b0;
		int a2=a[2][0]-b0;
		if(a1+b1==a[1][1] && a2+b2==a[2][2] && a1+b2==a[1][2] && a2+b1==a[2][1])
		{
            cout<<"Yes\n";
            return 0;
        }
	}
	cout<<"No";
	return 0;
}
