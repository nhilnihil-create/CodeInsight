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


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin>>n;
    bool b[300010];
    vll v,ans(n);
    rep2(i,1,30001){
        if(i%2==0||i%3==0){
            v.push_back(i);
        }
    }
    if(n==3){
        cout<<"2 5 63"<<endl;
        return 0;
    }
    ll cnt=0;
    rep(i,n-2){
        ans[i]=v[i];
        b[v[i]]=true;
        cnt+=v[i];
    }
    rep2(i,n-2,v.size()){
        if(cnt%2==0){
            if(v[i]%2==0){
                ans[n-2]=v[i];
                b[v[i]]=true;
                cnt+=v[i];
                break;
            }
        } else{
            if(v[i]%2==1){
                ans[n-2]=v[i];
                b[v[i]]=true;
                cnt+=v[i];
                break;
            }
        }
    }
    for(ll i:v){
        if(b[i]||i%2==1)continue;
        if(cnt%3==0){
            if(i%3==0){
                ans[n-1]=i;
                break;
            }
        }
        else if(cnt%3==1){
            if(i%3==2){
                ans[n-1]=i;
                break;
            }
        }
        else if(cnt%3==2){
            if(i%3==1){
                ans[n-1]=i;
                break;
            }
        }
    }
    rep(i,n){
        cout<<ans[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
    return 0;
}