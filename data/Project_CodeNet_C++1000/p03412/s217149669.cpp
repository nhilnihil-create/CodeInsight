#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int N;
vector<int>a,b;

int main(){
    cin >> N;
    a.resize(N); for (int i = 0; i < N; ++i) cin >> a[i];
    b.resize(N); for (int i = 0; i < N; ++i) cin >> b[i];

    int res = 0;
    for (int digit = 29; digit >= 0; --digit) {
        int bekihigh = 1 << (digit+1), bekilow = 1 << digit;
        for (int i = 0; i < N; ++i) a[i] %= bekihigh, b[i] %= bekihigh;
        sort(b.begin(), b.end());
        long long num = 0;
        for (int i = 0; i < N; ++i) {
            int add = 0;
            if (bekilow - a[i] >= 0) {
                add += lower_bound(b.begin(), b.end(), bekihigh - a[i])
                       - lower_bound(b.begin(), b.end(), bekilow - a[i]);
            }
            else {
                add += lower_bound(b.begin(), b.end(), bekihigh-a[i]) - b.begin();
                add += lower_bound(b.begin(), b.end(), bekihigh)
                       - lower_bound(b.begin(), b.end(), bekihigh + bekilow - a[i]);
            }
            num += add;
        }
        if (num & 1) res += bekilow;
    }

    cout << res << endl;

}