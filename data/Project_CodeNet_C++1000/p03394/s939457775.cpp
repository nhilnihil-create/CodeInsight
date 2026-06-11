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


vector<vector<li>> ans = {
    {},
    {6},
    {6, 12},
    {2, 4, 6},
    {2, 3, 4, 9},
    {2, 3, 4, 6, 9},
    {2, 3, 4, 8, 9, 10},
    {2, 3, 4, 6, 8, 9, 10},
    {2, 3, 4, 6, 8, 9, 10, 12}
};

vector<vector<li>> ans_small = {
    {},
    {},
    {},
    {2, 5, 63},
    {2, 3, 4, 9},
    {2, 3, 4, 6, 9},
    {2, 3, 4, 8, 9, 10},
    {2, 3, 4, 6, 8, 9, 10},
    {2, 3, 4, 6, 8, 9, 10, 12}
};


int main() {
    li n;
    cin >> n;
    if (n < 8) {
        for (auto v : ans_small[n]) {
            cout << v << " ";
        }
        cout << endl;
        return 0;
    }
    li nn = n / 8;
    rep(i, nn) {
        for (auto v : ans[8]) {
            cout << i * 12 + v << " ";
        }
    }
    li amari = n % 8;
    for (auto v : ans[amari]) {
        cout << nn * 12 + v << " ";
    }
    cout << endl;

    return 0;
}