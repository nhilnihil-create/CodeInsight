#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    double N, K;
    cin >> N >> K;

    double ans = 0;
    int X;
    if (N >= K){
        ans = (N-K+1)/N;
        X = K-1;
    }
    else X = N;


    FOR(i, 1, X){
        //cout << pow(0.5, ceil(log2(K/i))) << endl;
        ans += pow(0.5, ceil(log2(K/i))) * (1/N);
    }

    cout << fixed << setprecision(10) << ans << endl;
}