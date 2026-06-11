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
#include <random>
#define ll long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const int INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const int MOD = 1000000007;
const int MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    string s;
    cin>>s;
    ll n=s.size(),cnt=0,cnt0=0;
    vll v;
    rep(i,n-1){
        if(i!=n-2-i&&s[i]!=s[n-2-i]){
            cout<<-1<<endl;
            return 0;
        }
        if(s[i]=='1') cnt++;
        else{
            v.pb(i+1);
            cnt0++;
        }
    }
    if(cnt0==n-1||s[0]=='0'||s[n-1]=='1'){
        cout<<-1<<endl;
        return 0;
    }
    rep(i,cnt){
        cout<<i+1<<" "<<i+2<<endl;
    }
    ll now=cnt+2,l=cnt+1;
    ll now1=2;
    rep2(i,1,n-2){
        if(s[i]=='1') now1++;
        else{
            cout<<now1<<" "<<now<<endl;
            now++;
        }
    }
    return 0;
}
