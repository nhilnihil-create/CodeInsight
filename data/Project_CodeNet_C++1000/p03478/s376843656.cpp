#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int sum_int(int n){
    int res = 0;
    while(n>0){
        res += n%10;
        n /= 10;
    }
    return res;
}
int main(){
    cout << fixed << setprecision(10);
    int n,a,b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(sum_int(i) >= a && sum_int(i)<=b) ans+=i;
    }
    cout << ans << endl;
    return 0;
}