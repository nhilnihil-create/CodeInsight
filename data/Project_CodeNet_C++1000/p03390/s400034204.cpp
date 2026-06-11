#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long s,i,k,a,b;
    scanf("%d",&n);
    while(n--)
    {
        cin>>a>>b;
        if(a==b) {cout<<(a-1)*2<<"\n";continue;}
        s=a*b-1;
        i=sqrt(s);
        k=i*2-1;
        if(i*(i+1)>s)k--;
        if(i*i>s&&a!=b) k--;
        cout<<k<<"\n";
    }
    return 0;
}
