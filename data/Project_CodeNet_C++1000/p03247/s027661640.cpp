#include <bits/stdc++.h>
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
#define MOD 1000000007
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

PI x[1010];

li keta = 0;

li m;

inline vector<bool> solve_(li xx) {
    rep(i, keta)xx += bit(i);
    vector<bool> res(keta, false);
    for (li now = keta - 1; now >= 0; now--) {
        if (bit(now) * 2 <= xx) {
            xx -= bit(now) * 2;
            res[now] = true;
        }
    }
    //p2("", xx);
    //dumpi(res);
    return res;
}

inline string solve(PI xx) {
    string res = "";
    if ((xx.F + xx.S) % 2 == 0) {
        res = "L";
        xx.F++;
    }
    auto v_u = solve_(xx.F + xx.S);
    auto v_v = solve_(xx.F - xx.S);

    rep(i, keta) {
        if (v_u[i]) {
            // RU
            res = res + (v_v[i] ? "R" : "U");
        } else {
            // LD
            res = res + (v_v[i] ? "D" : "L");
        }
    }
    return res;
}

int main() {
    li n;
    cin >> n;
    set<li> st;
    li ma = 0;
    rin{
        cin >> x[i].F >> x[i].S;
        st.insert((x[i].F + x[i].S + 10000000000) % 2);
        ma = max(ma, max(abs(x[i].F + x[i].S), abs(x[i].F - x[i].S)));
    }
    while (ma > 0) {
        keta++;
        ma /= 2;
    }
    keta++;
    if (st.size() > 1) {
        puts("-1");
        return 0;
    }
    m = keta;
    if (*st.begin() == 0) {
        m++;
    }
    cout << m << endl;
    if (m > keta)cout << "1 ";
    rep(i, keta)cout << bit(i) << " "; cout << endl;
    rep(i, n) {
        cout << solve(x[i]) << endl;
    }

    return 0;
}