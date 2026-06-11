#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,a,b;
    cin>>n>>a>>b;
    if((b-a)%2==0){cout<<"Alice";}
    else{cout<<"Borys";}
    return 0;
}