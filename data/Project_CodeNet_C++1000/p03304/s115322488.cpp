#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, M, D;
    double x;
    cin >> N >> M >> D;
    x = 2 * (M - 1) * (N - D);
    x = x / N / N;
    if(D == 0){
        x = x / 2;
    }

    printf("%24.16lf\n", x);

}
