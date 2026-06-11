#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;  cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    ll p = 0, q = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]-b[i]>0) {
            q += a[i]-b[i];
        }
        else {
            p += (b[i]-a[i]+1)/2;
            q += (b[i]-a[i])%2;
        }
    }

    if (p >= q)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}