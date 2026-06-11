#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
bool rev(long long int a,long long int b)
{
    if(a>b)return true;
    else return false;
}
bool compa(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    if(a.first==b.first)
    {
        if(a.second.first>b.second.first)
        return true;
        else
        return false;
    }
    if(a.first<b.first)
    return true;
    else 
    return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    long long int a,b,c,d;
    string s;
    cin>>s;
    a=s[0]-'0';b=s[1]-'0';c=s[2]-'0';d=s[3]-'0';
    long long int v=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(i==0)
                v=a+b;
                if(i==1)
                v=a-b;
                if(j==0)
                v=v+c;
                if(j==1)
                v=v-c;
                if(k==0)
                v=v+d;
                if(k==1)
                v=v-d;
                if(v==7)
                {
                    char o1,o2,o3;
                    if(i==0)
                    o1='+';
                    if(i==1)
                    o1='-';
                    if(j==0)
                    o2='+';
                    if(j==1)
                    o2='-';
                    if(k==0)
                    o3='+';
                    if(k==1)
                    o3='-';
                    cout<<a<<o1<<b<<o2<<c<<o3<<d<<"=7";return;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
