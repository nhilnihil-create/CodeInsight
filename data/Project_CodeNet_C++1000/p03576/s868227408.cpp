#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=4*1e18;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> x(n),y(n),xx(n),yy(n);
    vector<vector<ll>> sum(n+1,vector<ll>(n+1));
    rep(i,n){
        cin >> x[i] >> y[i];
        xx[i]=x[i];
        yy[i]=y[i];
    }
    sort(xx.begin(),xx.end());
    sort(yy.begin(),yy.end());
    map<ll,ll> mx,my;
    rep(i,n){
        mx[xx[i]]=i+1;
        my[yy[i]]=i+1;
    }
    rep(i,n){
        ll nx=mx[x[i]];
        ll ny=my[y[i]];
        sum[nx][ny]++;
    }
    rep(i,n+1){
        rep(j,n){
            sum[i][j+1]+=sum[i][j];
        }
    }
    rep(i,n+1){
        rep(j,n){
            sum[j+1][i]+=sum[j][i];
        }
    }
    /*rep(i,n+1){
        rep(j,n+1){
            if(j) cout << " ";
            cout << sum[i][j];
        }
        cout << endl;
    }*/
    ll ans=INF;
    rep(a,n){
        for(ll b=a;b<n;b++){
            for(ll c=b;c<n;c++){
                for(ll d=c;d<n;d++){
                    vector<ll> p(4);
                    p[0]=a;
                    p[1]=b;
                    p[2]=c;
                    p[3]=d;
                    for(ll i=0;i<(1<<4);i++){
                        set<ll> s,t,u,v;
                        rep(j,4){
                            if((i>>j)%2==1){
                                s.insert(x[p[j]]);
                                t.insert(y[p[j]]);
                                u.insert(mx[x[p[j]]]);
                                v.insert(my[y[p[j]]]);
                            }
                            
                        }
                        if(s.size()<=1 || t.size()<=1) continue;
                        ll up=*v.rbegin();
                        ll dw=*v.begin();
                        ll ri=*u.rbegin();
                        ll le=*u.begin();
                        ll h=*t.rbegin()-*t.begin();
                        ll w=*s.rbegin()-*s.begin();
                        ll cnt=sum[ri][up]-sum[ri][dw-1]-sum[le-1][up]+sum[le-1][dw-1];
                        if(cnt>=k && h*w>0){
                            ans=min(ans,h*w);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

