#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}

signed main() {
    int N, K;
    cin >> N >> K;

    int res = 0;
    FOR(b, 1, N+1) {
        int p = N/b, r = N%b;
        res += p*max(0, b-K) + max(0, r-K+1);
    }
    if(K==0) res-=N;

    cout << res << endl;
    return 0;
}