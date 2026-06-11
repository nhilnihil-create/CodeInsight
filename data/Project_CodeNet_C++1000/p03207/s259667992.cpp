#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,ct=0,d,i,j,k;
    cin>>a;
    vector<long long>vc;
    for( i=0;i<a;i++)
    {
    cin>>b;
    vc.push_back(b);
    ct+=b;
    
    
    }
    sort(vc.begin(),vc.end());
    
  cout<<ct-vc[a-1]/2;



}
