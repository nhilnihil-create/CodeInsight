/**
*    author:  yuya1234
*    created: 30.06.2020 09:34:59
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

    int n;
    cin>>n;

    string s;
    cin>>s;

    int tmpE,tmpW,ans;
    tmpE=tmpW=0;
    ans=INT_MAX;

    int cntE[1000000],cntW[1000000];

    REP(i,n)
    {
        cntE[i]=tmpE;
        if(s[i]=='W')tmpE++;
    }
    REPD(i,n)
    {
        cntW[i]=tmpW;
        if(s[i]=='E')tmpW++;
    }

    REP(i,n)
    {
        ans=min(ans,cntE[i]+cntW[i]);
    }
  
    cout<<ans<<endl;

    return 0;
}