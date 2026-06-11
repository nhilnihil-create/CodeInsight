#include<bits/stdc++.h>
using namespace std;

int n,r,b;
string a;
int main()
{
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='R')
            ++r;
        else
            ++b;
    }
    if(r>b)
        cout<<"Yes";
    else
        cout<<"No";
}
