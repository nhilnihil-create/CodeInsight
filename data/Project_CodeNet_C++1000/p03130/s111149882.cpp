#include<bits/stdc++.h>
 
using namespace std;
 
int dgr[5];
 
int main()
{
    for(int i=1;i<=3;i++)
    {
      	int a,b;
      	cin>>a>>b;
        dgr[a]++;
        dgr[b]++;
    }
    for(int i=1;i<=4;i++)
    {
        if(dgr[i]>2) return cout<<"NO"<<'\n',0;
    }
    cout<<"YES"<<'\n';
}