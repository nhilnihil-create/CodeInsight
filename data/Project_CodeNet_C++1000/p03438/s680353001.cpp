#include<iostream>
#include<vector>
#include <math.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    ll add_one = 0, add_two = 0;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] > b[i])
            add_one += a[i] - b[i];
        if(a[i] < b[i])
            add_two +=(b[i] - a[i]) / 2;
    }
    cout << (add_one  <= add_two ? "Yes" : "No") << endl;
}
