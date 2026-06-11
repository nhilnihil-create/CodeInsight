

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll row,col;
    cin>>row>>col;
    char arr[row+5][col+5]={0};
    ll brr[row+5][col+5]={0};
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            ll cnt=0;
            if(arr[i][j]=='#')
            {
                brr[i][j]=50000;
            }
            else{
                for(int k=i-1;k<i+2;k++)
                {
                    for(int l=j-1;l<j+2;l++)
                    {
                        if(k<0 || k>=row || l<0 || l>=col)
                        {
                            continue;
                        }
                        else{
                            if(arr[k][l]=='#')
                            {
                                cnt++;
                            }
                        }
                    }
                }
                brr[i][j]=cnt;
            }
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
           if(brr[i][j]==50000)
           {
               cout<<"#";
           }
           else{
            cout<<brr[i][j];
           }
        }
        cout<<endl;
    }
}
