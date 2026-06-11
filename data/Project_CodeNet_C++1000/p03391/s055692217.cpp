#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[200002], b[200002];
    ll sum = 0;
    ll les = 10000000000000;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if(a[i] > b[i]) les = min(les, b[i]);
        sum += a[i];
    }
    if(les == 10000000000000) cout << 0 << endl;
    else cout << sum - les << endl;
}