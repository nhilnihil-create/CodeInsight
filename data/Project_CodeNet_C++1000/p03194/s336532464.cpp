#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define sortall(obj) sort(ALL(obj))
#define revall(obj) reverse(ALL(obj))
#define SortRevAll(obj) revall(sortall(obj))
typedef string str;
typedef long long ll;
const int mod=1e9+7;
const int INF=1e9;
const ll LINF=1e18;
#define VI vector<int>
#define P pair
#define M map
#define F first()
#define S second()
#define PB(a) push_back(a)
#define IN(a) insert(a)
#define ins(a) int a;cin >> a
#define lls(a) ll a;cin >> a
#define in(a) cin >> a
#define sts(a) string (a);cin >> a
#define For(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) For(i,0,n)
#define Forr(i,m,n) for(int i=n-1;i>=m;i--)
#define repr(i,n) Forr(i,0,n)
#define print(a) cout << a << endl
#define Endl cout << endl
#define YES(n) cout << ((n)? "YES" : "NO") << endl
#define Yes(n) cout << ((n)? "Yes" : "No") << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE" ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl
#define br(c,y,n) cout << ((c)? y : n) << endl

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    ll N,P,ans=1,T;
    in(N);in(T);
    P=T;
    For(i,2,sqrt(T)){
        ll cnt=0;
        while(P%i==0){
            P/=i;
            if(P>=1){
                cnt++;
            }
        }
        if(cnt>=N){
            ans*=pow(i,cnt/N);
        }
    }
    if(N==1)ans*=P;
    print(ans);
    return 0;
}
