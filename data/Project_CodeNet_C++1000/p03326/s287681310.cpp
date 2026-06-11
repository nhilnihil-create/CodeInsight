#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const ll INF = 1e+18;

int main(){
    int N,M;
    cin >>N>>M;
    vector<ll> x(N),y(N),z(N);
    vector<ll> sum;
    rep(i,N) cin >> x[i] >> y[i] >> z[i];
    ll ans=0;

    rep(l,2){
        rep(m,2){
            rep(n,2){
                priority_queue<ll> sum;
                ll tmp=0;
                rep(i,N){
                    sum.push(pow(-1,l)*x[i]+pow(-1,m)*y[i]+pow(-1,n)*z[i]);
                }

                rep(i,M){
                    tmp+=sum.top();
                    sum.pop();
                }
                ans=max(ans,tmp);
            }
        }      
    }
    cout << ans << endl;
    
    
}
