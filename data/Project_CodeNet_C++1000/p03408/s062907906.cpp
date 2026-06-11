#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,n1,max=0;
    cin>>n;
    string s;
    unordered_map<string,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        m[s]++;
    }
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        cin>>s;
        if(m.find(s)!=m.end())
        m[s]--;
    }
    for(auto x:m)
    {
        if(x.second>max)
        max=x.second;
    }
    if(max<=0)
        cout<<"0"<<endl;
    else
        cout<<max<<endl;
    return 0;
}