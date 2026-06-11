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


#define ABYSS -1
#define TO_BE_FILLED 0

vi solve(int N, int A, int B) {
    vi ans;
    if (A+B > N+1) return ans;
    if ((ll)A*B < (ll)N) return ans;
    if (A < B) {
        vi rev = solve(N, B, A);
        rep(i,N) rev[i] = (N+1)-rev[i];
        return rev;
    }
    // A >= B
    // A+B <= N+1
    // A*B >= N
    ans.assign(N, -1);
    if (B == 1) {
        rep(i,N) ans[i] = 1+i;
        return ans;
    }

    int rest = N-A, q = rest/(B-1), r = rest%(B-1), _r = (B-1)-r;
    int label=0;
    // for (int i=0;i<A;++i) {
#ifdef DEBUG
    fprintf(stderr, "N=%d,A=%d,B=%d; q=%d,r=%d|%d\n", N,A,B,q,r,_r);
#endif
    for (int a=0; a<A; ++a) {
        int bmax = 0;
        if (a < q) bmax = B-1;
        if (r != 0 && a == q) bmax = 1+r;
        for (int b=0; b<=bmax; ++b) {
            int fill_index = -1;

            int _b = (B-1)-b; //0...B-1
            if (_b < _r) {
                if (q <= a) continue;
                fill_index = _b*q + a;
            } else if (r != 0 && _b < B-1) {
                if (q+1 <= a) continue;
                fill_index = _r*q + (_b-_r)*(q+1) + a;
            } else {
                fill_index = rest + a;
            }
#ifdef DEBUG
            fprintf(stderr, "%d | (%d,%d|%d) -> %d\n", i, a,b,_b, fill_index);
#endif
            if (fill_index >= 0) {
                ans[fill_index] = ++label;
                if (label == N) goto done;
            }
        }
    }
 done:
    return ans;
}

int main() {
    int N,A,B; cin >> N >> A>> B;
    vi ans = solve(N,A,B);
    if (ans.size() != N) {
        cout << -1 << endl;
    } else {
        rep(i,N) {
            if (i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
