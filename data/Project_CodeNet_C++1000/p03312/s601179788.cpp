#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a[200010],sum[200010],ans=INF;
    cin>>n;
    rep(i,n){
        cin>>a[i];
        sum[i+1]=a[i]+sum[i];
    }
    rep2(i,2,n-1){
        ll p,q,r,s,p0,p1,q0,q1,r0,r1,s0,s1;
        p0=*lower_bound(sum,sum+n,sum[i]/2);
        q0=sum[i]-p0;
        p1=*(lower_bound(sum,sum+n,sum[i]/2)-1);
        q1=sum[i]-p1;
        if(abs(p0-q0)>=abs(p1-q1)){
            p=p1,q=q1;
        } else{
            p=p0,q=q0;
        }
        r0=*(lower_bound(sum,sum+n,sum[i]+(sum[n]-sum[i])/2));
        s0=sum[n]-r0;
        r0-=sum[i];
        r1=*(lower_bound(sum,sum+n,sum[i]+(sum[n]-sum[i])/2)-1);
        s1=sum[n]-r1;
        r1-=sum[i];
        if(abs(r0-s0)>=abs(r1-s1)){
            r=r1,s=s1;
        } else{
            r=r0,s=s0;
        }
        ll div=max(max(p,q),max(r,s))-min(min(p,q),min(r,s));
        ans=min(ans,div);
    }
    cout<<ans<<endl;
    return 0;
}