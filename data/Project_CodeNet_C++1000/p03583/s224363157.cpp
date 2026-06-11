#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    ll a,b,c;
    repr(i,1,3501) {
        repr(j,i,3501) {
            if (4*i*j-n*(i+j)<=0) continue;
            if ((i*j*n)%(4*i*j-n*(i+j))==0) {
                a=i;
                b=j;
                c=(i*j*n)/(4*i*j-n*(i+j));
                if (c>0) break;
            } 
        }
    }
    cout << a << ' ' << b << ' ' << c << endl;
    
    return 0;
}