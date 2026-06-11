/**
*    author:  yuya1234
*    created: 30.06.2020 10:21:49
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

    string s;
    cin>>s;

    string op[3];
    int sum;

    REP(i,2)
    {
        REP(j,2)
        {
            REP(k,2)
            {
                sum=0;
                if(i==0)
                {
                    op[0]="+";
                    sum=(int)(s[0]-'0')+(int)(s[1]-'0');
                }
                else
                {
                     op[0]="-";
                    sum=(int)(s[0]-'0')-(int)(s[1]-'0');
                }

                if(j==0)
                {
                    op[1]="+";
                    sum+=(int)(s[2]-'0');
                }
                else
                {
                     op[1]="-";
                    sum-=(int)(s[2]-'0');
                }

                if(k==0)
                {
                    op[2]="+";
                    sum+=(int)(s[3]-'0');
                }
                else
                {
                     op[2]="-";
                    sum-=(int)(s[3]-'0');
                }
                if(sum==7)
                {
                    cout<<s[0] + op[0] + s[1] + op[1] + s[2] + op[2] + s[3]<<"=7"<<endl;
                    i=j=k=2;
                }
            }
        }
    }

    return 0;
}