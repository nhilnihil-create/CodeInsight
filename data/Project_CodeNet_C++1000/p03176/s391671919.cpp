#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(NULL);
#define MAX 2000000000
#define MOD 1000000009
typedef long long ll;

ll n, h[200001],a[200001];
set<pair<ll,ll>> s;


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>a[i];

    s.insert({0,0});

    for(int i=1;i<=n;i++)
    {
        auto it=s.lower_bound({h[i],0});
        it--;
        ll val=it->second+a[i];
        s.insert({h[i],it->second+a[i]});
        
        it=s.lower_bound({h[i]+1,0});

        while(it!=s.end()&&val>=it->second)
        {
            auto tmp=it;
            tmp++;

            s.erase(it);
            it=tmp;
        }
    }

    auto it=s.end();
    it--;

    cout<<it->second;


	return 0;
}