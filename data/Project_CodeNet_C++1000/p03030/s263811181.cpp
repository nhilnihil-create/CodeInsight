#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

bool cmp(pair<string, pair<ll, ll> > p1, pair<string, pair<ll, ll> > p2) 
{
    if (p1.first != p2.first) 
        return (p1.first < p2.first);
    return (p1.second.first > p2.second.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    vector<pair<string,pair<ll,ll>>>arr;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin >> str;
        cin >> x;
        arr.push_back({str, {x, i + 1}});
    }
    sort(arr.begin(),arr.end(), cmp);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].second.second<<"\n";
    }
    return 0;
}
