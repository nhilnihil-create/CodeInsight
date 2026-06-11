#include<bits/stdc++.h>
using namespace std;

char arr[3][3];
int main()
{
   
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin>>arr[i][j];
    cout<<arr[1][1]<<arr[2][2]<<arr[3][3];

}
