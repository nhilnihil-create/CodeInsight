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
//int max(int a, int b) {if(b>a) return b; else return a;}
//int min(int a, int b) {if(b<a) return b; else return a;}
const int INF = 1e18;

signed main() {
    double n, m, d;
    cin >> n >> m >> d;
    cout << fixed << setprecision(10);

    if(d==0) {
        cout << (m-1)/n << endl;
    } else {
        cout << (m-1)*2.0*max(0.0, n-d)/(n*n) << endl;
    }

    return 0;
}