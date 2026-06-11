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

int N, A, B;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>A>>B;
    if(N<A+B-1||N>1LL*A*B){
        cout1(-1); return 0;
    }
    
    vector<int> T;
    int S=N-A;
    int cur=N;
    rep(i,A){
        int num=min(B-1,S)+1;
        S-=num-1;
        rep(j,num) T.push_back(cur-num+1+j);
        cur-=num;
    }
    reverse(all(T));
    for(auto v:T) cout<<v<<" ";
    cout<<endl;
}