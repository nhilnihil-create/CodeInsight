#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
#define EPS (1e-7)
#define INF (1e9 + 10)
#define PI (acos(-1))
#define MOD (1000000007)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N;
    ll C;
    cin >> N;
    cin >> C;
    ll tempx[N], v[N];
        REP(i, N) {
        cin >> tempx[i];
        cin >> v[i];
    }
    ll x[N+1];
    RREP(i, N+1){
        if (i == N){
            x[i] = C - tempx[N-1];
        } else if (i == 0) {
            x[i] = tempx[i];
        } else {
            x[i] = tempx[i] - tempx[i-1];
        }
    }
    ll ans = 0;
    ll At[N+1];//反時計周りにi個食ったときのカロリー
    ll Bt[N+1];//時計回りにi個食って戻ってきたときのカロリー
    REP(i, N+1) {
        if (i == 0){
            At[i] = 0;
            Bt[i] = 0;
        } else {
            At[i] = At[i-1] + v[i-1] - x[i-1];
            Bt[i] = Bt[i-1] + v[N-i] - 2 * x[N+1-i];
        }
    }
    REP(i, N+1) {
        if (i != 0) {
            chmax(At[i], At[i-1]);
            chmax(Bt[i], Bt[i-1]);
        }
    }
    REP(i, N+1) {
        chmax(ans, Bt[i] + At[N-i]);
    }
    reverse(x, x + N + 1);
    reverse(v, v + N);

    REP(i, N+1) {
        if (i == 0){
            At[i] = 0;
            Bt[i] = 0;
        } else {
            At[i] = At[i-1] + v[i-1] - x[i-1];
            Bt[i] = Bt[i-1] + v[N-i] - 2 * x[N+1-i];
        }
    }
    REP(i, N+1) {
        if (i != 0) {
            chmax(At[i], At[i-1]);
            chmax(Bt[i], Bt[i-1]);
        }
    }
    REP(i, N+1) {
        chmax(ans, Bt[i] + At[N-i]);
    }
    cout << ans << endl;
}