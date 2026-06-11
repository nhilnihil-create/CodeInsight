#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int>t(N+1);
    vector<int>x(N+1);
    vector<int>y(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> t[i] >> x[i] >> y[i];
        if(t[i]-t[i-1] < abs(x[i]-x[i-1])+abs(y[i]-y[i-1])) {
            cout << "No" << endl;
            return 0;
        }
        if(((t[i]-t[i-1])-abs(x[i]-x[i-1])-abs(y[i]-y[i-1]))%2 == 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}