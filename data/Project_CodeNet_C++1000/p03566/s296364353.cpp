#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    int N;
    cin >> N;
    vec<int> T(N+2),V(N+2),S(N+3);
    int tsum = 0;
    for(int i=1;i<=N;i++){
        cin >> T[i];
        T[i] *= 2;
        tsum += T[i];
        S[i+1] = S[i]+T[i];
    }
    for(int i=1;i<=N;i++) cin >> V[i];
    T[0] = 0,V[0] = 0;
    T[N+1] = tsum,V[N+1] = 0;
    S[N+2] = S[N+1];
    vec<double> mi(tsum+1,2e9);
    for(int i=0;i<=N+1;i++){
        int l = S[i],r = S[i+1];
//        cerr << l << " " << r << "\n";
        auto f = [&](int t)->double{
            if(l<=t && t<=r) return V[i];
            if(t<l) return -0.5*(t-l)+V[i];
            else return 0.5*(t-r)+V[i];
        };
        for(int j=0;j<=tsum;j++) mi[j] = min(mi[j],max(0.0,f(j)));
    }
    double ans = 0;
    for(int j=0;j<tsum;j++){
//        cerr << j << " " << mi[j] << "\n";
        ans += (mi[j]+mi[j+1])*0.25;
    }
    cout << fixed << setprecision(10) << ans << "\n";
}