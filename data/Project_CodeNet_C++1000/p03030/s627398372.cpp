#include<bits/stdc++.h>
#define int long long
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int32_t main()
{
    FastIO;
    int n;
    cin>>n;
    string s;
    set<string>str;
    int a;
    map<pair<string,int>,int>m;
    map<string,vector<int>>v;
    vector<int>vect;
    for(int i=1;i<=n;++i)
    {
        cin>>s>>a;
        m[make_pair(s,a)]=i;
        str.insert(s);
        v[s].push_back(a);
    }
    //sort(str.begin(),str.end());
    int c=-1;
    for(auto st:str)
    {
        c=INT_MAX;
        vect=v[st];
        sort(vect.begin(),vect.end(),greater<int>());
        for(int j=0;j<vect.size();++j)
        {
            cout<<m[make_pair(st,vect[j])]<<endl;
            //cout<<str[i]<<" "<<vect[j]<<" ";
        }
        vect.clear();
        //cout<<endl;
    }
    

}