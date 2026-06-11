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
    int N, sum = 0;
    cin >> N;

    vector<int> a1(N);
    vector<int> a2(N);

    REP(i, N){
        cin >> a1[i];
        sum += a1[i];
    }
    REP(i, N){
        cin >> a2[i];
        sum += a2[i];
    }

    int res = INF, num = 0, res_temp = 0;
    REP(i, N){
        res_temp = 0;
        FOR(j, i+1,N-1){
            res_temp += a1[j];
        }

        FORD(j, i-1, 0){
            res_temp += a2[j];
        }

        if (res_temp < res){
            res = res_temp;
            num = i;
        }
    }

    cout << sum - res << endl;
}