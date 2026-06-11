#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int num=n;
    int a[m+2]={0};
    while(n--)
    {
        int k;
        cin>>k;
        while(k--){
            int ind;
            cin>>ind;
            a[ind]++;
        }
    }
    int cnt=0;
    for(int i=1; i<=m; i++)
        if(a[i]==num)cnt++;
    cout<<cnt<<endl;
    return 0;
}
