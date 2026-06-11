#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    map<int,int> mii;
    rep(i,n){
        int d;
        cin >> d;
        mii[d]++;
    }
    bool ok = 1;
    int m;
    cin >> m;
    rep(i,m){
        int t;
        cin >> t;
        if(mii[t] == 0) ok = 0;
        else mii[t]--;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}