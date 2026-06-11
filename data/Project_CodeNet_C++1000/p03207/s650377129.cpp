#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,sum=0;

    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        sum +=a;
    }
    sort(v.begin(),v.end());
    a = v[n-1]/2.0;
    sum -=a;
    cout<<sum<<endl;

    return 0;
}
