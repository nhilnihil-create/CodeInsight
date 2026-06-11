#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ll n;
    cin>>n;
    vector<string>v(n);
    map<string,bool>m;
    bool ok=1;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v[i]=s;
        if(!m[s])
        {
            m[s]=1;
        }
        else
        {
            ok=0;

        }
        if(!i)
        {
            continue;
        }
        else
        {
            if(*v[i-1].rbegin()!=*v[i].begin())
            {
                ok=0;
            }
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
