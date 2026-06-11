#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
ll gcd(ll a,ll b){
    if(min(a,b)==0)return max(a,b);
    if(max(a,b)%min(a,b)==0)return min(a,b);
    return gcd(min(a,b),max(a,b)%min(a,b));
}
int main(){
    ll n;cin>>n;
    vector<ll>a(n);
    multiset<ll>st;
    rep(i,n){
        cin>>a[i];
        st.insert(a[i]);
    }
    sort(all(a));
    reverse(all(a));
    ll cnt=0;
    rep(i,n){
        if(!st.count(a[i]))continue;
        auto itr=st.lower_bound(a[i]);
        st.erase(itr);
        ll w=1;
        while(w<=a[i])w*=2;
        ll x=w-a[i];
        itr=st.lower_bound(x);
        if(*itr==x){
            cnt++;
            st.erase(itr);
        }
    }
    cout<<cnt<<endl;
}