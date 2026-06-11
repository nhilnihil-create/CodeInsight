#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    int d[31] {0};
    d[0] = k;
    for(int i = 1; i <= 30; i++){
        if((k >> i) & 1){
            d[i] = ((k >> (i + 1)) << (i + 1)) | ((1 << i) - 1);
        }
    }
    int a[100002];
    ll b[100002];
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll ans = 0;
    for(int i = 0; i <= 30; i++){
        ll sum = 0;
        for(int j = 0; j < n; j++) if((d[i] & a[j]) == a[j]) sum += b[j];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}