#include<iostream>
#include <bits/stdc++.h>
//1000000000000223
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, k ;
int main()
{
    IO
    cin>>n>>k;
    if(k>= (1<<n) || (n==1 && k==1))
        return cout<<-1, 0 ;
    if(n==1)
        return cout<<"0 0 1 1" , 0;
    cout<<k<<" ";
    for(int i=0; i<(1<<n); i++)
        if(i!=k)
            cout<<i<<" ";
    cout<<k<<" ";
    for(int i=(1<<n)-1; i>=0; i--)
        if(i!=k)
            cout<<i<<" ";
    return 0;
}
