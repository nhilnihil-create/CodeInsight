#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
ll n,a,b;
bool pos(ll cen,ll a,ll b,ll mid){
    if(cen <= 0 || cen > mid) return true;
    return cen*(a+mid+1-cen) < a*b;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    rep(i,1,n){
        cin>>a>>b;
        ll k1=0,k2=0;
        ll lo=1,hi=a-1,mid;
        while(lo <= hi){
            mid=(lo+hi)/2;
            ll cen = (mid+b+1)/2;


            if(pos(cen,b,a,mid) && pos(cen+1,b,a,mid) && b+mid < a*b && mid*(b+1) < a*b){
                k1=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        lo=1,hi=b-1;
        while(lo <= hi){
            mid=(lo+hi)/2;
            ll cen = (mid+a+1)/2;

            if(pos(cen,a,b,mid) && pos(cen+1,a,b,mid) && a+mid < a*b && mid*(a+1) < a*b){
                k2=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        ll inter = min(a-1-k1,b-1-k2);
        cout<<k1+k2+inter<<'\n';
    }

}

