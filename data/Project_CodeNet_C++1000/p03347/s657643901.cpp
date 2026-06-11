#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    long n;
    cin >> n;
    vector<long> a(n);
    for(auto &x: a) cin >> x;

    long r = 0;
    long l = n-1;
    for(int i=n-1; i>=0; i--) {
        if(a[i] == max(0l, i-l))
            continue;
        if(a[i] < max(0l, i-l) || a[i] > i) {
            cout << -1 << endl;
            return 0;
        }

        r += a[i];
        l = i - a[i];
    }
    cout << r << endl;
}
