#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int n,t,a;
    cin >> n >> t >> a;
    int h[n];
    rep(i,n)cin >> h[i];

    int ans;
    double x=0,b = INF;

    for(int i=0;i<n;i++){
        double tem = t -h[i] * 0.006;
        x = abs(a-tem);
        if(x<b){
            b=x;
            ans = i+1;
        }
    }

    cout << ans << endl;
    return 0;

}
