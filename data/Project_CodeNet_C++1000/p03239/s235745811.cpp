#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,a,b;
    vector<int>v1;
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(b<=t)
            v1.push_back(a);

    }

    sort(v1.begin(),v1.end());

    if(v1.size()==0)
        cout<<"TLE"<<endl;
    else
        cout<<v1[0]<<endl;

    v1.clear();
    return 0;
}
