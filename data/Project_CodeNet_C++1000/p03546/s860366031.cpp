#include<bits/stdc++.h>

using namespace std;

int jamil[69][69];
int ha;

int main()
{
int n,m;cin>>n>>m;


	for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            cin>>jamil[i][j];


	for(int k=0;k<10;k++)
        {for(int i=0;i<10;i++)
            {for(int j=0;j<10;j++)
                {jamil[i][j]=min(jamil[i][k]+jamil[k][j],jamil[i][j]);}}}

	for(int i=0;i<n;i++)
        {for(int j=0;j<m;j++)
            {int x;cin>>x;
                if(x==-1)continue;
                else {ha+=jamil[x][1];}}}

	cout<<ha;

return 0;
}
//  LoL
