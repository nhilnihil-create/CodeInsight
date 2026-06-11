#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    int count=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second-it->first>=0)
        {
            count+=it->second-it->first;
        }
        else count+=it->second;
    }
    cout<<count;
}