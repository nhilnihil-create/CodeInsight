#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    for(int i = 1; i <= n; i++){
        cin >> a.at(i);
    }
    int now = 0;
    long sum = 0;
    for(int i = 1; i <= n+1; i++){
        sum = sum + abs(now - a[i]);
        now = a[i];
    }
    int diff = 0;
    for(int i = 1; i <= n; i++){
        diff = abs(a[i-1]-a[i]) + abs(a[i]-a[i+1]) - abs(a[i-1]-a[i+1]);
        cout << sum - diff << endl;
    }
}