#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
const int INF = (1<<60);
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    const Int n=4;
    Int d[n][n];
    for(Int i=0;i<n;i++){
        for(Int j=0;j<n;j++){
            d[i][j] = 10000*(i!=j);
        }
    }

    for(Int i=1;i<n;i++){
        Int a,b;cin >> a >> b;
        a--,b--;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    for(Int k=0;k<n;k++){
        for(Int i=0;i<n;i++){
            for(Int j=0;j<n;j++){
                chmin(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    
    for(Int i=0;i<n;i++){
        for(Int j=0;j<n;j++){
            if(d[i][j]==3){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}