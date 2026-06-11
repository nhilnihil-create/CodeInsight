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
int main(){
    cout << fixed << setprecision(10);
    int a,b,t;
    cin >> a >> b >> t;
    int ans = 0;
    for(int i = 1; i <= t; i++){
        if(i%a == 0) ans+=b;
    }
    cout << ans << endl;
    return 0;
}