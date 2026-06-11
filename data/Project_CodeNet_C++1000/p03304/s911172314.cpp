#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main(){
    ll n,m,d;
    string S;
    cin >> n >> m >> d;
    ld cnt = 0;
    if(d != 0){
        cnt = n-2*d+n;
    }else{
        cnt = n;
    }
    //cnt = cnt * (m-1);
    ld tmp = (cnt/(n*n));
    ld ans = 0;//tmp/n;//tmp/n;//cnt;
    //vector<ld> DP(m+1);
    //DP[0] = 0;
    rep(i,m-1){
        ans += tmp;
    }
    //cout << tmp << endl;
    cout << setprecision(10) << ans << endl; 
}
