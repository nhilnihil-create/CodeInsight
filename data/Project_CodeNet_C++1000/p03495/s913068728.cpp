#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,k,x;
    cin>>n>>k;
    map<int,int>mp;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    if(mp.size()<=k)
        cout<<0<<endl;
    else
    {
        int m=mp.size();
        vector<int>v;
        for(auto x : mp)
            v.push_back(x.second);
        sort(v.begin(),v.end());
        int cnt=0;
        for(int i=0;i<m-k;i++)
            cnt+=v[i];
        cout<<cnt<<endl;
//        for(auto x : v)
//            cout<<x<<" ";
    }


}
