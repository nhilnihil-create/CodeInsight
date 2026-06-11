#include<bits/stdc++.h>
using namespace std;

int main()
{
long long int t,i,s=0,s1=0;
cin>>t;
int v[1000];
int c[1000];
for(i=0;i<t;i++)
{
    cin>>v[i];
}
for(i=0;i<t;i++)
{
    cin>>c[i];
}
for(i=0;i<t;i++)
{
    if(v[i]>=c[i])
    {
        s=s+v[i];
       s1=s1+c[i];
    }
}
cout<<s-s1<<endl;

}