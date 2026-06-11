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
int min(int a, int b) {if(b<a) return b; else return a;}


signed main() {
    int N;
    cin >> N;

    vi b(N);
    rep(i, N) cin >> b[i];
    
    vi res;
    int cnt = N;
    rep(i, N) {
        int seq = -1;
        for(int j=cnt-1; j>=0; j--) {
            if(b[j]==j+1) {
                seq = j;
                break;
            }
        }
        if(seq<0) {
            cout << seq << endl;
            return 0;
        }
        res.pb(seq+1);
        for(int j=seq; j<cnt; j++) {
            b[j] = b[j+1];
        }
        cnt--;
    }

    reverse(ALL(res));
    rep(i, N) {
        cout << res[i] << endl;
    }

    return 0;
}