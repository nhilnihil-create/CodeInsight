#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
using ll = long long;

int N;
vector<ll> x;
ll X;
int main(){
    cin>>N>>X;
    x.resize(N);
    rep(i,N) cin>>x[i];
    reverse(all(x));
    vector<ll> acc(N+1);
    rep(i,N) acc[i+1] = acc[i] + x[i];

    ll ans = 1e18;

    rep1(t,N){
        ll sm = X*t;
        for(int k=0;;k++){
            int l = k*t;
            int r = min(N,l+t);
            ll c = (k==0 ? 5 : k*2+3);
            sm += c*(acc[r]-acc[l]);
            if(sm>ans) break;
            if(r==N) break;
        }
        chmin(ans,sm);
    }
    cout<<ans+X*N<<endl;
}