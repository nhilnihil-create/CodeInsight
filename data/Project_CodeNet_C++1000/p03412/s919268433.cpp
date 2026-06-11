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

int N, ans, a[200009], b[200009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    rep(i,N) cin>>a[i];
    rep(i,N) cin>>b[i];
    
    for(ll v=(1<<28); v; v>>=1){
        
        rep(i,N) a[i]&=(v*2-1);
        rep(i,N) b[i]&=(v*2-1);
        
        sort(a,a+N); sort(b,b+N);
        int t=0;
        
        for(int i=N-1,j=0,k=0,l=0;i>=0;i--){
            while(j<N&&a[i]+b[j]<v) j++;
            while(k<N&&a[i]+b[k]<2*v) k++;
            while(l<N&&a[i]+b[l]<3*v) l++;
            t+=k-j+N-l;
            t&=1;
        }
        if(t) ans|=v;
    }
    cout1(ans);
}