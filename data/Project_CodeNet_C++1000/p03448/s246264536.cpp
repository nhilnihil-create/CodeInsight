/*  
    Talkin' to myself and feelin' old
    Sometimes I'd like to quit, nothin' ever seems to fit
    Hangin' around, nothin' to do but frown
    Rainy days and Mondays always get me down
    _________________________
    _________________________
    936 Hours of Solitude
    Quarantine_Day : 39
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int       ll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef pair<int, int>      pii;
typedef pair<ll, ll>		pll;

#define pb(n)           push_back(n)
#define GSORT(v)        sort(v.begin(), v.end(), greater<int>())
#define SORT(v)         sort(v.begin(), v.end());
#define REV(v)          reverse(v.begin(), v.end());
#define db(a)           cout<<#a<<" = "<<a<<endl;
#define FIN             freopen("in.txt","r",stdin);
#define FOUT            freopen("out.txt","w",stdout);
#define REP(i,n)        for(int i = (int)(0); i < (int)(n); i++)
#define FOR(i, a, b)    for(int i = (int)a; i <= (int)b; i++)    

#define MAX 90

bool issqr(int n){
    int sq = sqrt(n);
    return (sq * sq) == n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    int res(0);
    FOR(i, 0, a){
        FOR(j, 0, b){
            FOR(k, 0, c){
                if(((500 * i) + (100 * j) + (50 * k)) == d)res++;
            }
        }
    }
    cout<<res<<"\n";

    return 0;
}
