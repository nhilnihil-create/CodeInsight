#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define BR cout<<endl;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const ll mod=1000000007;

ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%mod;
    }
    return res;
}

double expect(int x){
    double kitai,tem=0;
    for(int i=1;i<=x;i++){
        tem += i;
    }
    kitai = tem/x;
    cout << kitai << endl;
    return kitai;
    
}

int main(){
    int n, m, c;cin >> n >> m >> c;
    int B[m];
    rep(i,m)cin >> B[i];

    int A[n][m];
    rep(i,n){
        rep(j,m){
            cin >> A[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++){
        int tem = 0;
        for (int j = 0; j< m; j++){
            tem += A[i][j] * B[j];
        }
        if(tem + c > 0)ans++;
    }

    cout << ans << endl;
    
    return 0;
}

