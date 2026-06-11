#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s1=0,s2=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i+=2)
    {
       s1+=v[i]; 
    }
    for(int i=1;i<n;i+=2)
    {
        s2+=v[i];
    }
    cout<<abs(s1-s2)<<"\n";
    return 0;
}