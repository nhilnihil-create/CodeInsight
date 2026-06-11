#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> muls;
    for (int i = 1; i*i <= m; ++i) {
        if (m%i == 0) {
            muls.push_back(i);
            muls.push_back(m/i);
        }
    }   
    sort(all(muls));
    int di = upper_bound(all(muls), m/n) - muls.begin(); 
    cout << muls[di-1] << endl;
    return 0;
}