#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


map<ll,int> prime_factor(ll n) {
    map<ll,int> res;
    repr(i,2,sqrt(n)+1) {
        while (n%i==0) {
            ++res[i];
            n/=i;
        }
    }
    if(n!=1) ++res[n];
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cnt(n+1);
    repr(i,2,n+1) {
        map<ll,int> pf=prime_factor(i);  
        repitr(itr,pf) cnt[itr->first]+=itr->second;
    }
    int p2=0,p4=0,p14=0,p24=0,p74=0;
    rep(i,n+1) {
        if (cnt[i]>=2) ++p2;
        if (cnt[i]>=4) ++p4;
        if (cnt[i]>=14) ++p14;
        if (cnt[i]>=24) ++p24;
        if (cnt[i]>=74) ++p74;
    }
    ll ans=0;
    ans+=p4*(p4-1)/2*(p2-2);
    ans+=p14*(p4-1);
    ans+=p24*(p2-1);
    ans+=p74;
    cout << ans << endl;

    return 0;   
}