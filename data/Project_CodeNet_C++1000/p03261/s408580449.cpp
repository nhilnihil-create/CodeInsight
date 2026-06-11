#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
    set<string>s ;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        v.push_back(str);
        s.insert(str);
    }
    if(s.size()!=n)
    {
    cout<<"No"<<endl;
    exit(0);
    }
    for(int i=1;i<n;i++)
        if(v[i-1][v[i-1].size()-1]!=v[i][0])
        {
            cout<<"No"<<endl;
            return 0;
        }
    cout<<"Yes"<<endl;
    return 0;
}