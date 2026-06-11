#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i<(int)m; i++)
#define ROF(i,n,m) for(int i=n; i>(int)m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define debug true
#define dprintf debug && printf

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

char s[MAXN];
vii ed;
int n;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    scanf("%s", s);
    n = strlen(s);

    if(s[0] == '0' || s[n-1] == '1'){
        printf("-1\n");
        return 0;
    }
    FOR(i,0,n-1) if(s[i] != s[n-2-i]){
        printf("-1\n");
        return 0;
    }

    int i = n/2 - 1;
    int sz, lst1, lst2, par1, par2;
    if(n&1){
        sz = 3;
        lst1 = 2, lst2 = 3, par1 = 1, par2 = 1;
        ed.pb({2,1});
        ed.pb({1,3});
    }
    else{
        sz = 4;
        if(s[i] == '0'){
            ed.pb({1,2});
            ed.pb({1,3});
            ed.pb({1,4});
            par1 = par2 = 1;
            lst1 = 2;
            lst2 = 3;
        }
        else{
            ed.pb({1,2});
            ed.pb({2,3});
            ed.pb({3,4});
            lst1 = 1;
            par1 = 2;
            par2 = 3;
            lst2 = 4;
        }
        i--;
    }
    while(i > 0){
        if(s[i] == '0'){
            ed.pb({par1,++sz});
            lst1 = sz;
            ed.pb({par2,++sz});
            lst2 = sz;
        }
        else{
            ed.pb({lst1, ++sz});
            par1 = lst1;
            lst1 = sz;
            ed.pb({lst2, ++sz});
            par2 = lst2;
            lst2 = sz;
        }
        i--;
    }

    for(auto e : ed){
        printf("%d %d\n", e.F, e.S);
    }

    return 0;
}
