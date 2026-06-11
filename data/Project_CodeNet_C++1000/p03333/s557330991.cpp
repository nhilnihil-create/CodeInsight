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

li n;
PI ls[100100];
PI rs[100100];

inline li calc(bool turn_l) {
    vector<bool> used(n, false);
    li pl = n - 1;
    li pr = 0;
    li pos = 0;
    li res = 0;
    rin{
        if (turn_l) {
            while (used[ls[pl].S]) {
                pl--;
            }
            if (ls[pl].F < pos) {
                break;
            }
            res += max(0ll, ls[pl].F - pos);
            pos = ls[pl].F;
            used[ls[pl].S] = true;
            pl--;
        } else {
            while (used[rs[pr].S]) {
                pr++;
            }
            if (rs[pr].F > pos) {
                break;
            }
            res += max(0ll, pos - rs[pr].F);
            pos = rs[pr].F;
            used[rs[pr].S] = true;
            pr++;
        }
        turn_l = !turn_l;
    }
    res += abs(pos);
    return res;
}

int main() {
    cin >> n;
    rin{
        cin >> ls[i].F;
        ls[i].S = i;
        cin >> rs[i].F;
        rs[i].S = i;
    }
    sort(ls, ls + n);
    sort(rs, rs + n);

    li res1 = 0;
    if (ls[n - 1].F > 0) {
        // 右行くのからスタート
        res1 = calc(true);
    }

    li res2 = 0;
    if (rs[0].F < 0) {
        res2 = calc(false);
    }

    //p2(res1, res2);
    cout << max(res1, res2) << endl;


    return 0;
}