#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n*(n-1)/2-n/2 << endl;
    for (int i=1; i<n; i++) {
        for (int k=i+1; k<=n; k++) {
            if (n%2==0) {
                if (i+k!=n+1)
                    cout << i << " " << k << endl;
            } else {
                if (i+k!=n)
                    cout << i << " " << k << endl;
            }
        }
    }
    return 0;
}
