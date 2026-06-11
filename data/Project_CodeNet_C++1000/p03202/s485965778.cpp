#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int a[n];rep(i,0,n)cin>>a[i];
    int c=0;
    rep(i,0,n-1){
        if(a[i]>=a[i+1]){
            c=1;
            break;
        }
    }
    if(c==0){
        cout<<1<<endl;
        return 0;
    }
    int u=n,d=1;
    while(u-d>1){
        int mid=(u+d)/2;
        unordered_map<int,int> mp;
        deque<int> dq;
        int cc=0;
        rep(i,1,n){
            if(a[i]>a[i-1]){
                continue;
            }
            else{
                for(;;){
                    if(dq.size()==0)break;
                    if(dq.back()>a[i]){
                        mp[dq.back()]=0;
                        dq.pop_back();
                    }
                    else break;
                }
                dq.push_back(a[i]);
                ll now=a[i];
                mp[now]++;
                while(now>0&&mp[now]==mid){
                    mp[now]=0;
                    now--;
                    mp[now]++;
                }
                if(now==0){
                    cc=1;
                    break;
                }
            }
        }
        if(cc==1)d=mid;
        else u=mid;
    }
    cout<<u<<endl;
}
