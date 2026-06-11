#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main()
{
    ll N, M;   cin >> N >> M;
    ll nmax = min(M, 2000000LL);
    ll ans = 1;
    if(M%N==0)  ans = M/N;
    else{
        for(ll i=1; i<nmax; i++){
            if(M % i == 0 && M / i * N <= M){
                ans = M/i;
                break;
            }
            if(M % i == 0 && i * N <= M)    ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}