#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
    ll n,m,a,b;
    cin>>n;
    string s;
    vector<string> v,v1;
    v.push_back(" ");
    REP(i,1,n)
    {
        cin>>s;
        v.push_back(s);        
    }
    v1=v;
    sort(v1.begin(),v1.end());
    REP(i,1,n)
    {
        REP(j,i+1,n)
        {
            if(v1[i]==v1[j])
            {
                cout<<"No";
                return 0;
            }
        }
    }
    REP(i,2,n)
    {
        if(v[i-1].back()!=v[i].front())  
        {
            cout<<"No";
            return 0;
        }      
    }
    cout<<"Yes";
}
