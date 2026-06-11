#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    long n;
    cin >> n;
    vector<long> p(n);
    for(auto &x: p) cin >> x, x--;

    vector<long> rev(n);
    for(int i=0; i<n; i++)
        rev[p[i]] = i;

    long r = 1;
    long s = 1;
    for(int i=1; i<n; i++) {
        if(rev[i] > rev[i-1])
            r = max(r, ++s);
        else
            s = 1;
    }
    cout << (n-r) << endl;
}
