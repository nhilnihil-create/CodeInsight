/**
*    author:  yuya1234
*    created: 26.06.2020 11:25:49
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

    int c[3][3];

    REP(i,3)
    {
        cin>>c[i][0]>>c[i][1]>>c[i][2];
    }

    int sum=0;

    REP(i,3){
        REP(j,3){
            sum+=c[i][j];
        }
    }

    string ans="No";

    if(sum/3==c[0][0]+c[1][1]+c[2][2] 
    && sum/3==c[0][2]+c[1][1]+c[2][0]
    && sum/3==c[1][0]+c[0][1]+c[1][2]+c[2][1]-c[1][1])ans="Yes";

    cout<<ans<<endl;


        

    return 0;
}