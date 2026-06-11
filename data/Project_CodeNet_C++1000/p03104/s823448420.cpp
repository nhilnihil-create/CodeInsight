#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(i,n)cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

ll solve(ll n){
    ll ret=0;

    if(n <= 0) return 0;

    //数列{0,1...B-1,B}のXORの累計和は
    //Bi,1,Bi+1,0 ... の繰り返しになる
    int m = n % 4;
    switch(m){
        case 0:
            ret = n;
            break;
        case 1:
            ret = 1;
            break;
        case 2:
            ret = n+1;
            break;
        case 3:
            ret = 0;
            break;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll a,b;
    cin>>a>>b;

    //数列{0,1...B-1,B}のXORの和は
    //Bi,1,Bi+1,0 ... の繰り返しになる
    //ll ans = (xorsumA ^ xorsumB) ^ a;
    ll ans;
    ans = solve(a-1) ^ solve(b);
    
    cout << ans << endl;
    return 0;
}