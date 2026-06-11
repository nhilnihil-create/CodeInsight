#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n;
    cin >> n;
    vector<long long int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    
    // roop = accumulate(b.begin(), b.end(), 0) - accumulate(a.begin(), a.end(), 0);
    
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        if(b[i] > a[i]) sum -= (b[i] - a[i])/2;
        else if(b[i] < a[i]) sum += a[i] - b[i];
    }

    if (sum <= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
