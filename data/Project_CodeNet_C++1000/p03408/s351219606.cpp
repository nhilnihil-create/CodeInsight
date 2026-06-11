/**
*    author:  yuya1234
*    created: 25.06.2020 14:56:58
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n;

    map<string,int> card;
    string s;

    REP(i,n)
    {
        cin>>s;
        if(card.count(s)==0)
            card.insert(make_pair(s,1));
        else
            card[s]++;
    }

    cin>>m;
    REP(i,m)
    {
        cin>>s;
        if(card.count(s)==0)
            card.insert(make_pair(s,-1));
        else
            card[s]--;
    }

    int ans=-100;
    for(auto it=card.begin(); it!=card.end(); ++it)
    {
        ans=max(ans,it->second);
    }

    if(ans>0)cout<<ans<<endl;
    else cout<<0<<endl;

    return 0;
}