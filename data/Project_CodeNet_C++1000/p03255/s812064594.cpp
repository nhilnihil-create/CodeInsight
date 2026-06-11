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
typedef pair<LL,LL> P;
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<20;
typedef unsigned long long uLL;


int main(){
    int n;cin >> n;
    uLL x;cin >> x;
    vector<uLL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<uLL> cum(n+1,0);
    sort(ALL(a),greater<uLL>());
    for (int i = 0; i < n; i++) {
        cum[i+1]+=cum[i]+a[i];
    }
    uLL ans = ULONG_MAX;
    for (int k = 1; k <= n; k++) {
        uLL tmp = (n+k)*x;
        for (uLL i = 0; i*k <= n; i++) {
            if((i+1)*k>n){
                if(i==0) tmp += (cum[n] - cum[i*k])*5;
                else tmp += (cum[n] - cum[i*k])*(2*(i+1)+1);
                break;
            }
            else{
                if(i==0) tmp += (cum[(i+1)*k] - cum[i*k])*5;
                else tmp += (cum[(i+1)*k] - cum[i*k])*(2*(i+1)+1);
            }
        }
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
