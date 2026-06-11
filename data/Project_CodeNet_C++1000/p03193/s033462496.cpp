#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int n,h,w,ans = 0;
    cin >> n >> h >> w;

    repi(i,n,0){
        int a,b;
        cin >> a >> b;
        if(a >= h && b >= w)ans++;
    }
    cout << ans << endl;
    return 0;
}