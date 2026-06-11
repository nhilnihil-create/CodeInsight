#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main(){
ll n,k;
cin >> n >> k;
double sum;
for(int i=1;i<=n;i++){
    ll now = i;
    double p;
    if(now>=k) p=1;
    else{
    p=1;
        while(now<k){
            now*=2;
            p/=2;
        }
    }
    sum+=p;
}
double ans = sum/n;
printf("%.10lf",ans);
return 0;
}