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
const int INF = 1e18;

signed main() {
    string s;
    cin >> s;
    int N = s.size();
    int acnt = 0;
    int res = 0;
    int seq = 0;
    while(seq < N) {
        if(s[seq]=='A') acnt++;
        else if(s[seq]=='B') {
            if(seq+1 >= N) break;
            switch(s[seq+1]) {
                case 'A' :
                    acnt = 1;
                    break;
                
                case 'B' :
                    acnt = 0;
                    break;
                
                case 'C' :
                    res += acnt;
                    break;
            }
            seq++;
        } else if(s[seq]=='C') acnt = 0;
        seq++;
    }

    cout << res << endl;

    return 0;
}