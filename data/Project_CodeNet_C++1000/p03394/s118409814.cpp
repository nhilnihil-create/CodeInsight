#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }


void solve(int N) {
    vector<int> a;
    a.reserve(N+4);
    if (N < 6) {
        a = vector<int> {2,5,63};
        int S = accumulate(ALL(a), 0);
        // a = vector<int> {2,5,20,63};
        // a = vector<int> {2,5,20,30,63};
        for (int i=4; i<=N; ++i) {
            a.pb(0);
            for (int x=3; x<=30000; ++x) {
                if (find(ALL(a), x) != a.end()) continue;
                a[i-1] = x;
                S += x;
                if (all_of(ALL(a), [&](int ai){ return gcd(S, ai) != 1; })) break;
                a[i-1] = 0;
                S -= x;
            }
        }
    } else {
        for (int i=0,b=0; i<N; i+=4,b+=6) {
            a.pb(b+2);
            a.pb(b+3);
            a.pb(b+4);
            a.pb(b+6);
        }
        a.erase(a.begin()+N, a.end());
        int last_6k = a.back() - a.back() % 6;
        int next_6k = last_6k + 6;
        int next_6k_4 = next_6k + 4;
        if (a.back() < next_6k_4 - 6) next_6k_4 -= 6;
        // 2 3 4 6 8 9 ...
        ll S = accumulate(ALL(a), 0LL);
        switch (S % 6) {
            case 0: break;
            case 2: a[4] = next_6k; break;
            case 3: a[5] = next_6k; break;
            case 5: a[5] = next_6k_4; break;
        }
    }

    sort(ALL(a));
    rep(i, N) {
        cout << a[i];
        if (i < N-1) cout << " ";
    }
    cout << endl;
}

int main() {
    int N; cin >> N;
    solve(N);
    return 0;
}
