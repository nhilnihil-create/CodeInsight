#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,a,s=0;
    vector<long long>v;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        v.push_back(a-i);
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    {
        s+=abs(v[i]-v[n/2]);
    }
    cout<<s<<endl;
}
