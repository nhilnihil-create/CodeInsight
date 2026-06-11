#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,ct=0,d,i,j,k;
    cin>>a>>b;
    vector<long long >vc;
   // vector<long long >tc;
   // vector<long long >tv;
    for(i=0;i<a;i++)
    {
    cin>>j>>k;
    if(k<=b)
    {
    vc.push_back(j);
   // tc.push_back(k);
    //tv.push_back(k*j);
    }
    }
    if(vc.size()==0)
    cout<<"TLE";
    else
    {

    sort(vc.begin(),vc.end());
    cout<<vc[0];}



}
