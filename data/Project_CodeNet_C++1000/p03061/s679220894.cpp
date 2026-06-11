#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;

ll calc_gcd(ll x,ll y){
    if(y==0) return x;
    return calc_gcd(y,x%y);
}

ll calc_lcm(ll x,ll y){
    return (x/calc_gcd(y,x%y))*y;
}

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;
template<typename T>
struct RMQ{
    // const T INF=numeric_limits<T>::max();
    const T INF=0;
    int n;
    vector<T> dat;
    RMQ(int n_):n(),dat(n_*4,INF){
        int x=1;
        while(n_>x){
            x*=2;
        }
        n=x;
    }

    void update(int i,T x){
        i += n - 1;
        dat[i] = x;
        while(i>0){
            i=(i-1)/2;
            dat[i]=calc_gcd(dat[i*2+1],dat[i*2+2]);
        }
    }

    T query(int a,int b){
        return query_sub(a,b,0,0,n);
    }
    T query_sub(int a,int b,int k,int l,int r){
        if(r<=a||b<=l){
            return INF;
        }
        else if(a<=l&&r<=b){
            return dat[k];
        }
        else{
            T vl = query_sub(a,b,k*2+1,l,(l+r)/2);
            T vr = query_sub(a,b,k*2+2,(l+r)/2,r);
            return calc_gcd(vl,vr);
        }
    }
};
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin>>n;
RMQ<ll> rmq(n);
vector<int> a(n);
rep(i,n){
    cin>>a[i];
    rmq.update(i,a[i]);
}
ll max_val=1;
rep(i,n){
    ll vl = rmq.query(0,i);
    ll vr = rmq.query(i+1,n);
    max_val = max(max_val,calc_gcd(vl,vr));
}
cout<<max_val<<endl;
return 0;
}