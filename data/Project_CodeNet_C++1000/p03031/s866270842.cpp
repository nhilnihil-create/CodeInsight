/**
*    author:  yuya1234
*    created: 07.07.2020 09:52:55
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define ALL(v) (s).begin(), (s).end()
#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    vector<int> s[m];
    REP(i,m)
    {
        int k;
        cin>>k;
        REP(j,k)
        {
            int ss;
            cin>>ss;
            ss--;
            s[i].emplace_back(ss);
        }
    }

    int p[m];
    REP(i,m)cin>>p[i];

    int res=0;
    for(int bit=0;bit<(1<<n);bit++)
    {
        int ans=0;
        REP(i,m)
        {
            int cnt=0;
            REP(j,SZ(s[i]))
            {
                if(bit&(1<<s[i][j]))cnt++;
            }
            if(cnt%2==p[i])ans++;
        }
        if(m==ans)res++;
    }

    cout<<res<<endl;

    return 0;
}