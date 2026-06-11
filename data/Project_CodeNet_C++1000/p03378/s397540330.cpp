#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,m,x,a[201];

    cin>>n>>m>>x;

    for(int i=0;i<m;i++) cin>>a[i];

    int left=0,right=0;

    for(int i=0;i<m;i++)
    {
        if(a[i]<x) right++;
        else left++;
    }
    cout<<min(left,right);

    return 0;
}
