#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main(){
    long double n,k;
    long double ans=0;
    long double cnt=0;
    cin >> n >> k;
    rep2(i,1,n+1){
        cnt=0;
        int now = i;
        while(now<k){
            //if(i>=k)break;
            now*=2;
            cnt++;
        }
        ans+=pow(0.5,cnt);
    }

    cout << fixed << setprecision(16) << ans*(1/n);

    return 0;
}