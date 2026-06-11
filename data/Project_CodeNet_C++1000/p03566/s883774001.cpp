#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    vector<int> t(N),v(N),T(N+1);
    rep(i,N){
        cin >> t[i];
    }
    rep(i,N){
        cin >> v[i];
    }
    T[0]=0;
    rep(i,N){
        T[i+1]=T[i]+t[i];
    }
    rep(i,N){
        T[i+1]*=2;
    }
    vector<double> ms(T[N]+1,100000);
    rep(i,N){
        for (int j=T[i];j<=T[i+1];j++){
            ms[j]=min(ms[j],(double)v[i]);
        }
    }
    ms[T[N]]=0;
    for (int i=T[N]-1;i>=0;i--){
        ms[i]=min(ms[i+1]+0.5,ms[i]);
    }
    ms[0]=0;
    for (int i=1;i<=T[N];i++){
        ms[i]=min(ms[i-1]+0.5,ms[i]);
    }
    double ans=0;
    for (int i=1;i<T[N];i++){
        ans+=ms[i];
    }
    ans/=2.0;
    cout << fixed << setprecision(6);
    cout << ans << endl;
}