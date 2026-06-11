#include <bits/stdc++.h>
#define repl(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    int cnt_e = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i]%2 == 0)cnt_e++;
    }
    cout << pow(3,n) - pow(2,cnt_e) << endl;
    return 0;
}