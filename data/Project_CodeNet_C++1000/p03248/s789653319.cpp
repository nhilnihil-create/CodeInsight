// skip until line 65
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <istream>
#include <iterator>
#include <sstream>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;

#define BR "\n"
#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define ALL(cont) begin(cont),end(cont)
#define AS_MOD(a, b) ((((a) % (b) ) + (b)) % (b))
#define MO(a) AS_MOD(a,mod)
#define FEACH(it, cont) for(auto (it) = begin(cont); it!=end(cont);++it)
#define FEACHR(it, cont) for(auto (it) = rbegin(cont); it!=rend(cont);++it)
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define getll() ([](){ll s;scanf("%lld", &s);return s;})()
#define getld() ([](){ld s;scanf("%Lf", &s);return s;})()
#define prl(P) printf("%lld", P)
#define prd(P) printf("%.10Lf", P)
#define pr(P) printf(P)
#define MAX(V, T) V=max(V,T)
#define MIN(V, T) V=min(V,T)

#define DumpArray(cont, from, to) for(int __i=from;__i<to;++__i) {cout<<"(" <<__i<<": " << cont[__i]<<")";} cout<<endl;

/*
 * ***_bound(6)
 * 5 6 6 6 6 6 7 7 7
 *   ^lower    ^upper
 * void reverse(c.begin(), c.end())
 *
 * graph
 * seg tree
 * dp
 * brute force
 */
struct Comparator{
    int operator()(int l, int r) const {
        return r<l;
    }
};
struct Vec;
//set<int, Comparator> S;

// solution below
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
int N;
vector<P> G;
void no() {
    cout<<-1<<endl;
    exit(0);
}
int main() {
    cout.precision(15);
    cout << fixed;
    string S;
    cin >> S;
    N=S.size();
    // check
    if (S[0]!='1'||S[N-1]!='0')no();
    for(int i=0;i<N-1;++i) {
        if (S[i]!=S[N-i-2])no();
    }
    //
    int p=0,c=1;
    while(c<N) {
       if (S[c-1]=='1') {
           G.pb({p,c});
           p=c;
       } else {
           G.pb({p,c});
       }
       c++;
    }
    REP(i,N-1) {
        cout<<G[i].fi+1 << " " << G[i].se+1<<endl;
    }


}
