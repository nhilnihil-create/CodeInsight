#include<iostream>
//#include<algorithm>
#include<map>
using namespace std;
int main()
{
    int n,i,s=0;
    cin>>n;
    int m[n];
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    //sort(m,m+n);
    map<int,int>mp;
    for(i=0;i<n;i++)
    {
        mp[m[i]]++;
    }
    for(auto i:mp)
    {
        if(i.first>i.second)
        {
            s=s+i.second;
        }
        else
        {
            s=s+i.second-i.first;
        }
    }
    cout<<min(n,s)<<endl;
    return 0;
}
