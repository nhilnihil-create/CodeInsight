#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n;
    cin>>n;
    vector<int> v={111,222,333,444,555,666,777,888,999};
    cout<<*lower_bound(v.begin(),v.end(),n)<<endl;
}