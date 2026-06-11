#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    ll k,a,b;
    cin >> k >> a >> b;
    ll ans1=1;
    if(k<=a-2||b-a<=2) ans1 += k;//交換できない時と、交換しても割に合わない時
    else{
        k -= a-1;
        ans1 += (a-1)+(k/2)*(b-a);
        ans1+=(k%2);
    } 
    cout << ans1 << endl;
    return 0;
}    