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
// #define int ll
using namespace std;
const int INF (1 << 30);
const ll LLINF (1LL << 55LL);
const int MOD = 1000000007;
const int MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n,d[60],t[20]={},now[30]={},ans=0;
    vll v;
    cin>>n;
    map<ll,ll> mp;
    mp[0]++;
    rep(i,n){
        cin>>d[i];
        mp[d[i]]++;
        t[d[i]]++;
    }
    rep(i,13){
        if((i==0||i==12)&&mp[i]>=2){
            cout<<0<<endl;
            return 0;
        }
        else if(mp[i]>=3){
            cout<<0<<endl;
            return 0;
        }
    }
    now[0]=1;
    rep2(i,1,12){
        if(mp[i]==2){
            now[i]++;
            now[24-i]++;
        }
        else if(mp[i]==1){
            v.push_back(i);
        }
    }
    if(mp[12]) now[12]++;
    rep(bit,(1<<(v.size()))){
        ll now2[30];
        rep(i,24){
            now2[i]=now[i];
        }
        rep(i,v.size()){
            if(bit&(1<<i)){
                now2[v[i]]++;
            } else{
                now2[24-v[i]]++;
            }
        }
        ll fi=0,en=0,ans0=30,bef=0;
        rep2(i,1,24){
            if(now2[i]){
                en=i;
                if(i!=bef)ans0=min(ans0,i-bef);
                bef=i;
            }
        }
        if(en!=0)ans0=min(fi+24-en,ans0);
        ans=max(ans,ans0);
    }
    cout<<ans<<endl;
    return 0;
}