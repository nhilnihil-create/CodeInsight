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
    int N, K;
    cin >> N >> K;

    int h[N];
    REP(i, N){
        cin >> h[i];
    }

    sort(h, h+N, greater<int>());

    int res = INF, temp = 0;
    REP(i, N-K+1){
        temp = h[i] - h[i+K-1];

        if (temp < res){
            res = temp;
        }
    }
    
    cout << res << endl;
}