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

ll gcd(ll a, ll b){
    if (a%b == 0){
        return(b);
    }
    else{
        return(gcd(b, a%b));
    }
}

int main() {
    int N;
    cin >> N;

    ll A[N];    
    REP(i, N){
        cin >> A[i];
    }

    sort(A, A+N);

    ll res = gcd(A[0], A[1]);
    FOR(i, 2, N-1){
        res = gcd(res, A[i]);
        if(res == 1){
            break;
        }
    }
    cout << res << endl;
}