#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector <long long> t(N+1, 0);
    vector <long long> x(N+1, 0);
    vector <long long> y(N+1, 0);
    for (long long i=1; i<=N; i++) {
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }
    bool ok=true;
    for (long long i=1; i<=N; i++) {
        long long dt, dx, dy;
        dt = t.at(i) - t.at(i-1);
        dx=abs(x.at(i)-x.at(i-1));
        dy=abs(y.at(i)-y.at(i-1));
        if(dt < dx+dy) ok=false;
        if((dt-dx-dy)%2 == 1) ok=false;
    }
    if (ok) cout << "Yes";
    else cout << "No";
}
