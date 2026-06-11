#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s;
    cin>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    if(s<t)cout<<"Yes";
    else cout<<"No";
}
