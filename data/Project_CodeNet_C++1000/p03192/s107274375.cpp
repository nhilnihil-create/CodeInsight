#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,ck=0,y;
    char arr[5];

    cin>>y;
   sprintf(arr,"%d",y);
   for(i=0;i<4;i++)
    {
        if(arr[i]=='2')
        {
            ck=ck+1;
        }
    }
    cout<<ck<<endl;


    return 0;
}

