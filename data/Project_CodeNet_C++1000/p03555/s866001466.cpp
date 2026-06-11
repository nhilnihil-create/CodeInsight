#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[4][4],b[4][4];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++)
            cin>>a[i][j];
    }
    b[0][0]=a[1][2];
    b[0][1]=a[1][1];
    b[0][2]=a[1][0];
    b[1][0]=a[0][2];
    b[1][1]=a[0][1];
    b[1][2]=a[0][0];
   for(int i=0;i<2;i++){
        for(int j=0;j<3;j++)
            if(a[i][j]!=b[i][j])
            {
                cout<<"NO";
                return 0;
            }
    }


        cout<<"YES";
}




