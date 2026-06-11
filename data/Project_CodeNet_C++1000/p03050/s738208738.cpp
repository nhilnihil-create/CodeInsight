#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#include<numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    ll N;   cin >> N;
    ll ans = 0;
    ll p = min(N,1000000LL);
    for(ll i=1; i<p; i++){
        if((N-i)%i == 0){
            if((N-i)/i > i) ans += (N-i)/i;
        }
    }
    cout << ans << endl;
    return 0;
}