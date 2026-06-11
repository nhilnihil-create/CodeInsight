/*  
    And solitare's the only game in town
    And every road that takes him
    Takes him down
    And by himself it's easy to pretend
    He'll never love again
    _________________________
    _________________________
    960 Hours of Solitude
    Quarantine_Day : 40
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int       ll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef pair<int, int>      pii;
typedef pair<ll, ll>		pll;

#define pb(n)           push_back(n)
#define GSORT(v)        sort(v.begin(), v.end(), greater<ll>())
#define SORT(v)         sort(v.begin(), v.end());
#define REV(v)          reverse(v.begin(), v.end());
#define db(a)           cout<<#a<<" = "<<a<<endl;
#define FIN             freopen("in.txt","r",stdin);
#define FOUT            freopen("out.txt","w",stdout);
#define REP(i,n)        for(int i = (int)(0); i < (int)(n); i++)
#define FOR(i, a, b)    for(int i = (int)a; i <= (int)b; i++)    

#define MAX 200005

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll k;
    vl v(3);
    cin>>v[0]>>v[1]>>v[2]>>k;
    SORT(v);
    cout<<(v[0] + v[1] + ((1<<k) * v[2]))<<"\n";

    return 0;
}
