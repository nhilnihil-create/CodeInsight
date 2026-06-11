#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    long n, z, w;
    cin >> n >> z >> w;
    vector<long> a(n);
    for(auto &x: a) cin >> x;

    vector<long> dpx(n, 0), dpy(n, 1e10);

    dpx[n-1] = abs(a[n-2] - a[n-1]);
    dpy[n-1] = abs(a[n-2] - a[n-1]);

    for(int i=n-2; i>0; i--) {
        dpy[i] = abs(a[i-1] - a[n-1]);
        for(int j=i+1; j<n; j++)
            dpy[i] = min(dpy[i], dpx[j]);

        dpx[i] = abs(a[i-1] - a[n-1]);
        for(int j=i+1; j<n; j++)
            dpx[i] = max(dpx[i], dpy[j]);
    }
    {
        int i = 0;
        dpy[i] = abs(z - a[n-1]);
        for(int j=i+1; j<n; j++)
            dpy[i] = min(dpy[i], dpx[j]);

        dpx[i] = abs(w - a[n-1]);
        for(int j=i+1; j<n; j++)
            dpx[i] = max(dpx[i], dpy[j]);
    }

    cout << dpx[0] << endl;
}
