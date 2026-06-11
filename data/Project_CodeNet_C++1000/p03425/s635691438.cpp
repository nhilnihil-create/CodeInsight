#include<bits/stdc++.h>
using namespace std;

#define int long long int 


signed main()
{
    int n;
    cin>>n;
    vector<string> s;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        s.push_back(str);
    }
   string march="MARCH";
    map<char,int> m;
    for(auto i:s)
    {
       if(string::npos!=march.find(i[0],0))
       m[i[0]]++;
    }
    int ans=0;
    for(int i=0;i<march.size()-2;i++)
    for(int j=i+1;j<march.size()-1;j++)
    for(int k=j+1;k<march.size();k++)
    ans+=m[march[i]]*m[march[j]]*m[march[k]];
    cout<<ans<<endl;
}