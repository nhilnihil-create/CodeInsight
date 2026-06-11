#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define de cout << "line : " << __LINE__ << " debug" << endl;

struct UnionFind{
    vector<long long> par,r;

    //はじめに全てが根であるとしておく
    UnionFind(long long N):par(N),r(N,1){iota(par.begin(),par.end(),0);}

    long long root(long long x){//根に当たるまで再帰で探す
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    bool same(long long x,long long y){//つながっているかどうか判定
        return root(x) == root(y);
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
    }

    REP(i,N){
        if(UF.same(i,i + N)){
            cout << (long long)(N-1)*N/2 - M << endl;
            return 0;
        }
    }
    long long b = 0,w = 0;
    REP(i,N){
        if(UF.same(0,i)) b++;
        else w++;
    }
    cout << (long long)b*w - M << endl;
}
