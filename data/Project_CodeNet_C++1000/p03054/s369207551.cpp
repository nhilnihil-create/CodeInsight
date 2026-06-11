#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
typedef long long ll;
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}

int main(){
    int H, W; cin >> H >> W;
    int N; cin >> N;
    int x, y; cin >> x >> y; x--, y--;
    string S, T;
    cin >> S;
    cin >> T;
    int left = 0;
    int right = W-1;
    int up = 0;
    int down = H-1;
    bool f = true;
    for(int i=N-1;i>=0;--i) {
        if(T[i]=='L' && right+1<W) right++;
        if(T[i]=='R' && left-1>=0) left--;
        if(S[i]=='L') left++;
        if(S[i]=='R') right--;
        if(left>right) {
            f = false;
            break;
        }
    }
    for(int i=N-1;i>=0;--i) {
        if(T[i]=='U' && down+1<H) down++;
        if(T[i]=='D' && up-1>=0) up--;
        if(S[i]=='U') up++;
        if(S[i]=='D') down--;
        if(down<up) {
            f = false;
            break; }
    }
    if(down<x || x<up || left>y || y>right) f = false;
  //cout << up << " " << down << " " << left << " " << right << endl;
    cout << (f ? "YES" : "NO") << endl;
    return 0;
}