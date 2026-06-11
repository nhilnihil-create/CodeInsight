#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef ll _loop_int;
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

ll n;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    if(n==0){
        cout << "0" << endl;
        return 0;
    }
    string ans;
    int cnt=1;
    while(true){
        //DEBUG(n);
        ans = to_string(abs(n)%2) + ans;
        n = (n-(abs(n)%2)) / -2;
        if(n==0) break;
    }

    cout << ans << endl;
    return 0;
}