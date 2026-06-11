#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;
    vector<vector<int>> v(m);
    for(int i=0;i<m;i++)
    {
        int k;cin>>k;
        for(int j=0;j<k;j++)
        {
            int s;cin>>s;
            v[i].push_back(s-1);
        }
    }

    vector<int> p(m);
    for(int i=0;i<m;i++)cin>>p[i];

    int ans=0;

    int sz=pow(2,n);
    for(int i=0;i<sz;i++)
    {
        bool ok=true;
        for(int j=0;j<m;j++)
        {
            int cnt=0;
            for(auto s:v[j])
            {
                if(i&1<<s)cnt++;
            }
            if(cnt%2!=p[j])ok=false;
        }
        if(ok)ans++;
    }

    cout<<ans<<"\n";

    return 0;
}
