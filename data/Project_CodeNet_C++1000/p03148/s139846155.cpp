#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define be begin
#define en end
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(a) (a).be() , (a).en()
#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)        //repeat n times
#define REP2(i,s,n) for(LL (i)=(s);(i)<(n);(i)++)   //repeat from s to n 
#define REPD(i,n) for(LL (i)=(n);(i)>=0;(i)--)      //repeat from n to 0
#define REPD2(i,s,e) for(LL (i)=(s);(i)>=(e);(i)--) //repeat from s to e
#define RANGE(i,v) for(auto &(i):v)                  //repeat range
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))          //array size

using LL = long long;

template<typename T1,typename T2> using P = pair< T1, T2 >;
using Pii = P<int,int>;
using Pll = P<LL,LL>;
using Pdd = P<double,double>;
using Psi = P<string,double>;

template<typename T> using V = vector< T >;
using Vi = V<int>;
using Vll = V<LL>;
using Vs = V<string>;

template<typename T1,typename T2> using M = map< T1, T2>;
using Mii = M<int, int>;

template<typename T>
T count_nonzero(V<T> v){return count_if(ALL(v),[](int x){return x != 0;});}

const LL INFLL = 1LL<<40;

int main(){
    LL n,k;
    cin>>n>>k;
    V<Vll> sushi(n);
    REP(i,n){
        LL t,d;
        cin>>t>>d;
        t--;
        sushi[t].pb(d);
    }
    
    for(auto &v : sushi){
        sort(ALL(v),greater<LL>());
        if(v.empty()) v.pb(-INFLL);
    }

    sort(ALL(sushi),[&](Vll a, Vll b){return a[0]>b[0];});

    LL oishisa = 0;
    priority_queue<LL> q;
    REP(i,k){
        oishisa += sushi[i][0];
        REP2(j,1,sushi[i].size()) q.push(sushi[i][j]);
    }
    REP2(i,k,n){
        REP(j,sushi[i].size()) q.push(sushi[i][j]);
    }

    LL manzoku = oishisa + k*k;
    REPD2(x,k-1,1){
        LL v = sushi[x][0];
        LL w = q.top();
        if(v<w){
            q.pop();
            oishisa += w;
            q.push(v);
            oishisa -= v;
        }
        manzoku = max(manzoku, oishisa + x*x);
    }

    cout<<manzoku<<endl;

    return 0;
}

