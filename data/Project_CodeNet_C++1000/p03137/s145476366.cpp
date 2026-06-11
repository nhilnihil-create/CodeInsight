#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    int N,M;
    cin >> N >> M;
    vint X(M);
    cin >> X;
    sort(X.begin(),X.end());
    if(N >= M){
        cout << 0 << endl;
        return 0;
    }
    vint L;
    REP(i,M-1){
        L.pb(abs(X[i]-X[i+1]));
    }
    sort(L.begin(),L.end(),greater<int>());
    int ans = abs(X[M-1]-X[0]);
    REP(i,N-1){
        ans -= L[i];
    }
    cout << ans << endl;
}