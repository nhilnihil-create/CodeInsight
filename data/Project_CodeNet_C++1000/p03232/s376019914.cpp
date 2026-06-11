#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;

vector<LL> fact;
vector<LL> inver(200001);
 
LL combi(int n,int r){
    if(n<r||n<0||r<0) return 0;
    return fact[n]%mod*inver[n-r]%mod*inver[r]%mod;
}
 
 
LL fpow(LL a, LL n){
    LL x = 1;
    while(n > 0){
        if(n&1){
            x=x*a%mod;
        }
        a=a*a%mod;
        n >>= 1;
    }
    return x;
}
 
void set_combi(){
    LL s=1;
    fact.push_back(1);
    for(int i=1;i<=200000;i++){
        s*=i;
        s%=mod;
        fact.push_back(s);
    }
    inver[200000]=fpow(fact[200000],mod-2);
    for(int i=199999;i>=0;i--){
        inver[i]=inver[i+1]*(i+1)%mod;
    }
}
 

int main(){
    LL N;cin >> N;
    vector<LL> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    set_combi();
    vector<LL> cum(N+1,0);
    for (int i = 0; i < N; i++) {
        cum[i+1] = (cum[i] + fact[N]*fpow(i+1,mod-2)%mod)%mod;
    }
    LL ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + (cum[N-i] + cum[i+1] - cum[1] )*a[i])%mod;

    }
    cout << ans << endl;
    return 0;
}
