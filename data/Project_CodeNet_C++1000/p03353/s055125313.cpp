#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string s,p;
set<string>v;
int main()
{
    ft
    int t,i,j,n,m,x=0,k;
    cin>>s>>k;
    n=s.size();
    for(i=0; i<n; i++)
    {
        p.clear();
        m=min(i+k,n);
        for(j=i; j<m; j++)
        {
            p+=s[j];
            v.insert(p);
        }
    }
    for(auto cc:v)
    {
        x++;
        if(x==k)
        {
            cout<<cc<<"\n";
            break;
        }
    }
    return 0;
}