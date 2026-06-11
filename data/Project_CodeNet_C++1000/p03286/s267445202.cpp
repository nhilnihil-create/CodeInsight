#include<bits/stdc++.h>
using namespace std;

#define int long long int 
void ans(int n)
{
    if(n==0)
    {cout<<0<<endl;
       return ;}
    string str="";
    while(n!=0)
    {
        int x=(n%2LL+2LL)%2LL;
        char c=(char)x+'0';
        str.insert(str.begin(),c);
        n=(n-x)/-2LL;
    }
    cout<<str<<endl;
}
int32_t main()
{
    int n;
    cin>>n;
    ans(n);
}