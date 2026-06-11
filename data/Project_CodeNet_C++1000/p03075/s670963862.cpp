#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5];
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4];
    bool flag=true;
    int k;
    cin>>k;
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            int p=arr[j]-arr[i];
            if(p>k)flag=false;
        }
    }
    if(flag)cout<<"Yay!"<<endl;
    else cout<<":("<<endl;
}
