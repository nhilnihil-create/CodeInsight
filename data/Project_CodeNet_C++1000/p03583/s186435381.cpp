#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const ll MOD=998244353;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    int a,b,c;
    repr(i,1,3510) {
        repr(j,1,3510) {
            ll k=4*i*j-n*i-n*j;
            if (k>0) {
                ll kk=n*i*j;
                if (kk%k==0) {
                    a=i;
                    b=j;
                    c=kk/k;
                }
            } 
        }
    } 
    cout << a << ' ' << b << ' ' << c << endl;

    return 0; 
}
