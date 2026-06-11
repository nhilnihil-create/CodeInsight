#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,y,cnt=0;
    cin>>x>>y;
    for(long long i=x;i<=y;i*=2)
    	++cnt;
    cout<<cnt;
    return 0;
}