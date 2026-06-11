    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef pair<int,int> P;
    typedef pair<ll,ll> l_l;
    const int INF=1001001000;
    const int mINF=-1001001000;
    const ll LINF=1010010010010010000;
    template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
    a = b;
    return true;
    }
    return false;
    }
    template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
    a = b;
    return true;
    }
    return false;
    }
    double lim[40100];
    void update(int now,double t,double v){
        now*=2;
        t*=2;
        for(int i=now;i<=now+t;i++){
            chmin(lim[i],v);
        }
    }
    int main(){
        int n;cin >> n;
        vector<double> t(n),v(n);
        for(int i=0;i<n;i++) cin >> t[i];
        for(int i=0;i<n;i++) cin >> v[i];
        int tot=0;
        for(int i=0;i<n;i++) tot+=t[i];
        fill(lim,lim+40100,INF);
        int now=0;
        for(int i=0;i<n;i++){
            update(now,t[i],v[i]);
            now+=t[i];
        }
        lim[0]=0;
        lim[2*tot]=0;
        for(int i=0;i<=2*tot;i++) chmin(lim[i+1],lim[i]+0.5);
        for(int i=2*tot;i>=0;i--) chmin(lim[i-1],lim[i]+0.5);
        double ans=0.0;
        for(int i=0;i<2*tot;i++){
            ans+=(lim[i]+lim[i+1])/2*0.5;
        }
        cout << setprecision(10) << ans << endl;
        return 0;
    }