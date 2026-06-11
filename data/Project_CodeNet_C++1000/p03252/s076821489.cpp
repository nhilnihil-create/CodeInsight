#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define all(v) v.begin() , v.end()
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int32_t main()
{   fastio;

    string a , b;
    cin>>a>>b;
    map<char , set<char>>mp;
    map<char , set<char>>ap;
    for(int i=0; b[i]; i++)
    {
        mp[b[i]].insert(a[i]);
    }
    for(int i=0; b[i]; i++)
    {
        ap[a[i]].insert(b[i]);
    }
    int fl=0;
    for(char i='a'; i <= 'z'; i++)
    {
        if(mp[i].size() <= 1 && ap[i].size() <= 1) continue;
        else fl=1;
    }
    if(fl)cout<<"No\n";
    else cout<<"Yes\n";

}