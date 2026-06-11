#include "bits/stdc++.h"
using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RREP(i,n) RFOR(i,0,n)
#define RREPS(i,n) RFOR(i,1,n+1)
#define ALL(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define debug(x) cout << #x << ": " << x << endl

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define INF (1L << 30)
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using ll = long long;
#define int ll

bool Fcomp(const pair<int,int>& firstElof, const pair<int,int>& secondElof)
{return firstElof.F < secondElof.F;}
bool Scomp(const pair<int,int>& firstElof, const pair<int,int>& secondElof)
{return firstElof.S < secondElof.S;}

//**********

signed main(void) {
    
    int n=0;
    vector<int> a;
    
    scanf("%lld",&n);
    REP(i,n){
        int sc;
        scanf("%lld",&sc);
        a.pb(sc);
    }
    sort(ALL(a));
    reverse(ALL(a));
    double half = a[0]/2.0;
    double ans = a[0]*1.0;
    //debug(half);debug(ans);
    FOR(i,1,n){
        if(abs(ans-half)>=abs(a[i]-half)) {
            ans = a[i];
      //      debug(ans);
        }
    }

    printf("%lld %lld\n",a[0],int(ans));

    return 0;
    
}




