#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    return p1.second<p2.second;
}
int main()
{
    long long n,i,k,c,l,s=0,j;
    cin>>n>>c;
    set<int>st;
    map<int,int>mp;
    vector<pair<int,int>>v;
    for(i=0;i<n;i++)
    {
        cin>>k;
        st.insert(k);
        mp[k]++;
    }
    j=st.size();
    //cout<<st.size()<<endl;
    if(st.size()<=c)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else
    {
        for(auto i:mp)
        {
            v.push_back(make_pair(i.first,i.second));
        }
        sort(v.begin(),v.end(),cmp);
        l=j-c;
        for(i=0;i<l;i++)
        {
            s=s+v[i].second;
        }
        cout<<s<<endl;
        /*for(auto i:v)
        {
            cout<<i.first<< " "<<i.second<<endl;
        }*/

    }
    return 0;
}
