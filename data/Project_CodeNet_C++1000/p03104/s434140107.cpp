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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll a,b;
    cin>>a>>b;

    //数列{0,1...B-1,B}のXORの和は
    //Bi,1,Bi+1,0 ... の繰り返しになる
    if(b==0){
        cout << "0" << endl;
        return 0;
    }
    const int keta = 12;
    ll xorsumA=0, xorsumB=0;

    int m = (a==0) ? 0 : a%4;
    switch(m){
        case 0:
            xorsumA = a;
            break;
        case 1:
            xorsumA = 1;
            break;
        case 2:
            xorsumA = a+1;
            break;
        case 3:
            xorsumA = 0;
            break;

    }

    m = (b==0) ? 0 : b%4;
    switch(m){
        case 0:
            xorsumB = b;
            break;
        case 1:
            xorsumB = 1;
            break;
        case 2:
            xorsumB = b+1;
            break;
        case 3:
            xorsumB = 0;
            break;

    }

    ll ans = (xorsumA ^ xorsumB) ^ a;
    cout << ans << endl;
    return 0;
}