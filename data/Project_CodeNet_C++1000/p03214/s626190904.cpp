#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<double> a(n, 0);
    double sum = 0.0;
    for(int i = 0; i < n; ++i) {
        cin >> a.at(i);
        sum += a.at(i);
    }

    double ave = sum/(double)n;
    double min = 1000.0;
    int minno = 0;
    for(int i = 0; i < n; ++i) {
        if(abs(a.at(i)-ave) < min) {
            min = abs(a.at(i)-ave);
            minno = i;
        }
    }

    cout << minno << endl;
}