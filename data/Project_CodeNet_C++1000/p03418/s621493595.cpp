#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    ll n,k;
    cin >> n >> k;
    int i;
    ll ans = 0;
    if(k == 0){
        cout << n*n << endl;
        return 0;
    }
    for(i = k+1;i <= n;++i){
        int temp= n/i;
        int spare = n%i;
        ans += temp*(i-k);
        if(spare >= k){
            ans += spare-k+1;
        }
    }
    cout << ans << endl;
    return 0;
}