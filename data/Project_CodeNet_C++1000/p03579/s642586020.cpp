#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr ll INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

struct UnionFind{
    vector<long long> par,r;

    //はじめに全てが根であるとしておく
    UnionFind(long long N):par(N),r(N,1){iota(par.begin(),par.end(),0);}

    long long root(long long x){//根に当たるまで再帰で探す
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    long long deep(long long x,long long A){
        if(par[x] == x) return A;
        else{A++;return deep(par[x],A);}
    }

    bool same(long long x,long long y){//つながっているかどうか判定
        return par[x] == par[y];
    }

    long long size(long long x){ //根の大きさを判定する
        return r[root(x)];
    }

    void unite(long long x, long long y){//根が同じでなかったらつなげる
        x = root(x), y = root(y);
        if(x == y) return;
        if(r[x] < r[y]) swap(x,y); //値を小さいほうを根にする
        r[x] += r[y];
        par[y] = x;
        return;
    }
};

vector<long long> G[100100];
long long num[100100] = {};
ll b = 0,w = 0;
bool used[100100] = {};

void dfs(long long X,char C){
    if(used[X]) return;
    else used[X] = 1;
    if(C == 'b'){b++;C = 'w';}
    else{w++;C = 'b';}
    REP(i,G[X].size()){
        dfs(G[X][i],C);
    }
}

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    long long N,M;cin >> N >> M;
    UnionFind UF(2*N);
    long long A,B;
    REP(i,M){
        cin >> A >> B;A--;B--;
        UF.unite(A,B + N);
        UF.unite(A + N,B);
        G[A].pb(B);G[B].pb(A);
    }
    long long sum = 0,sq = 0;
    REP(i,N) sum += i;


    REP(i,N){
        if(UF.same(i,i + N)){
            cout << sum - M << endl;
            return 0;
        }
    }
    dfs(0,b);
    sq = b*w;
    cout << sq - M << endl;
}