#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n, roop;
    cin >> n;
    vector<long long int> a(n), b(n);
    for (int i=0; i<n; i++) {
        long long int tmpa;
        cin >> tmpa;
        a[i] = tmpa;
    }
    for (int i=0; i<n; i++) {
        long long int tmpb;
        cin >> tmpb;
        b[i] = tmpb;
    }
    
    roop = accumulate(b.begin(), b.end(), 0ll) - accumulate(a.begin(), a.end(), 0ll);
    
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        if(b[i] - a[i] > 0) sum += ((b[i] - a[i]) + 1)/2;
    }
    
    if (sum <= roop) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
