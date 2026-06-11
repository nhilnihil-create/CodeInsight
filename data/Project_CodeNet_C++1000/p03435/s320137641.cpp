#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{

    int c[3][3];
    int a[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          cin>>c[i][j];
    
    for(int i=1;i<3;i++)
        for(int j=0;j<3;j++)
        a[i][j]=c[i][j]-c[i-1][j];
    

    for(int j=0;j<3;j++)
    a[0][j]=c[0][j]-c[2][j];

    int f=1;
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            if(a[i][j]!=a[i][j+1])
            f=0;

  
      
    if(f)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;

}
