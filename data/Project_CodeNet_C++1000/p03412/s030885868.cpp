#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int N, ans, a[200009], b[200009], c[600009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    rep(i,N) cin>>a[i];
    rep(i,N) cin>>b[i];
    
    ll ret=0;
    rep(i,29){
        rep(x,N) c[x]=b[x]&((1<<(i+1))-1);
        sort(c,c+N);
        rep(x,2*N) c[N+x]=c[x]+(1<<(i+1));
        ll tot=0;
        rep(x,N){
            int y=a[x]&((1<<(i+1))-1);
            tot+=lower_bound(c,c+3*N,(4<<i)-y)-lower_bound(c,c+3*N,(3<<i)-y);
        }
        if(tot%2) ret+=1<<i;
    }
    cout1(ret);
}