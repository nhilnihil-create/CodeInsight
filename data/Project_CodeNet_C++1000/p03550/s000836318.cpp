#include<bits/stdc++.h>
using namespace std;


#define li          long long int
#define rep(i,to)   for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)    for(li i=(li)(start);i<((li)(to));i++)
#define pb          push_back
#define sz(v)       ((li)(v).size())
#define bgn(v)      ((v).begin())
#define eend(v)     ((v).end())
#define allof(v)    (v).begin(), (v).end()
#define dodp(v,n)       memset(v,(li)n,sizeof(v))
#define bit(n)      (1ll<<(li)(n))
#define mp(a,b)     make_pair(a,b)
#define rin rep(i,n)
#define EPS 1e-12
#define ETOL 1e-8
typedef pair<li, li> PI;

#define INF bit(60)

#define DBGP 1


#define idp if(DBGP)
#define F first
#define S second
#define p2(a,b)     idp cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)       idp cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define p4(a,b,c,d)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl
#define p5(a,b,c,d,e)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl
#define p6(a,b,c,d,e,f)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<endl
#define p7(a,b,c,d,e,f,g)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<endl
#define p8(a,b,c,d,e,f,g,h)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<endl
#define p9(a,b,c,d,e,f,g,h,i)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<endl
#define p10(a,b,c,d,e,f,g,h,i,j)        idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<"\t"<<j<<endl
#define foreach(it,v)   for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define p2p(x)      idp p2((x).F, (x).S)
#define dump(x,n)   idp{rep(i,n){cout<<x[i]<<" ";}puts("");}
#define dump2(x,n)  idp{rep(i,n){cout<<"["<<x[i].F<<" , "<<x[i].S<<"] ";}puts("");}
#define dumpi(x)    idp{foreach(it, x){cout<<(*it)<<" ";}puts("");}
#define dumpi2(x)   idp{foreach(it, x){cout<<"["<<(it)->F<<" , "<<(it)->S<<"] ";}puts("");}

#define read2d(a,w,h)   rep(i,h)rep(j,w)cin>>a[i][j]
#define dump2d(a,w,h)   rep(i,h){rep(j,w)cout<<a[i][j]<<" ";puts("");}

typedef pair<li, li> PI;

// dp1[i][j] : Xがi番目、Yがj番目でXの手番なときのスコア最大値
// dp1[i][j] = max(dp2[j+1-n][j])
//li dp1[2020][2020];
// dp2[i][j] : Xがi番目、Yがj番目でYの手番なときのスコア最小値
// dp2[i][j] = min(dp1[])
//li dp2[2020][2020];

// X,Yの初期値が関係するのは本当にわずかなシーンだけなので、それ以外をまず計算する
// dp1[i] : Yがi番目を取ってた時のスコア最大値（Xのターン）
li dp1[3030];
// dp2[i] : Xがi番目を取ってた時のスコア最小値（Yのターン）
li dp2[3030];

li n, z, w;
li a[2020];

int main() {
    cin >> n >> z >> w;
    rin{
        cin >> a[i];
    }
    if (n == 1) {
        cout << abs(a[0] - w) << endl;
        return 0;
    }
    dp1[n - 2] = abs(a[n - 2] - a[n - 1]);
    dp2[n - 2] = abs(a[n - 2] - a[n - 1]);
    for (li i = n - 3; i >= 0; i--) {
        dp1[i] = abs(a[i] - a[n - 1]);
        repp(j, i + 1, n - 1) {
            dp1[i] = max(dp1[i], dp2[j]);
        }
        dp2[i] = abs(a[i] - a[n - 1]);
        repp(j, i + 1, n - 1) {
            dp2[i] = min(dp2[i], dp1[j]);
        }
    }

    li res = abs(w - a[n - 1]);
    rep(i, n - 1) {
        res = max(res, dp2[i]);
    }

    cout << res << endl;


    return 0;
}