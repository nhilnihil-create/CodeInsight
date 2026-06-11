#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    map<string , int> blue , red;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        blue[s]++;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        red[s]++;
    }

    int ans =0;
    map<string ,int>::iterator  it = blue.begin();
    while( it!= blue.end())
    {
        string temp = it->first;
        int temp2 = it->second;

        ans = max( ans , temp2 - red[temp] );
        it++;
    }
    cout<<ans;
}