#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll m,k;
    cin>>m>>k;
    if(m==1){
        if(k==0){
            printf("0 0 1 1\n");
        }else cout<<-1<<endl;
    }else{
        if(k>=(1<<m)) cout<<-1<<endl;
        else{
            V<ll> a((1<<(m+1)));
            a[0]=k;
            ll cnt=(1<<m+1);
            a[(1<<m)]=k;
            for(ll i=1;i<(1<<m);i++){
                if(i<=k){
                    a[i]=a[cnt-i]=i-1;
                }else{
                    a[i]=a[cnt-i]=i;
                }
            }
            rep(i,(1<<(m+1))) cout<<a[i]<<' ';
            cout<<endl;
        }
    }
}