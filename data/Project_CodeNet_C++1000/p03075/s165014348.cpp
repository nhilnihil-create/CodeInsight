#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,min=123,max=0;
    for(int i=0;i<5;i++)
    {
        cin>>n;
        if(min>n) min=n;
        if(max<n) max=n;
    }
  	cin>>k;
    if(max-min>k) cout<<":(";
    else cout<<"Yay!";
}