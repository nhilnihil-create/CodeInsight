#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back 
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define ld long double
#define int long long int 
#define F first 
#define S second
signed main()
{
    fast;
    string s;
    cin>>s;
    int n = s.size();
    int wins = 15-n;
    for(int i=0;i<n;i++)
        if(s[i]=='o')
            wins++;
    if(wins>=8)
        cout<<"YES";
    else cout<<"NO";
}