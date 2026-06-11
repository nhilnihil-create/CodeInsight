#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> v(n+1);
    for(int i=1; i<n; ++i)
    {
        if(s[i-1]=='A' && s[i]=='C')
            v[i]=1;
    }
    for(int i=1; i<=n; ++i)
        v[i]+=v[i-1];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<v[r-1] - v[l-1]<<endl;
    }
    return 0;
}