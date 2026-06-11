#include<bits/stdc++.h>

using namespace std;


int main(void) {
    long n;
    cin >> n;

    vector<long> a(n), b(n);
    for(int i=0; i<n; i++)
        cin >> a[i] >> b[i];

    long m = 1e9;
    for(int i=0; i<n; i++)
        if(a[i]-b[i] > 0 && m > b[i]) m = b[i];

    if(m == 1e9) {
        cout << 0 << endl;
        return 0;
    }

    long r = 0;
    for(int i=0; i<n; i++)
        r += a[i];
    r -= m;
    cout << r << endl;
}
