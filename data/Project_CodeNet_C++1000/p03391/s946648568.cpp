#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[200005], b[200005];
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        s += a[i];
    }
    ll l = s;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]) l = min(l, b[i]);
    }
    cout << s - l << endl;
}
