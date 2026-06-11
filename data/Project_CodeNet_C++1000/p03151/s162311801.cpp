#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n), d(n);
    for(auto& e : a) cin >> e;
    for(auto& e : b) cin >> e;
    int64_t sum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        d[i] = a[i] - b[i];
        if(d[i] < 0){
            sum += d[i];
            cnt++;
        }
    }
    if(accumulate(begin(d), end(d), 0LL) < 0){
        cout << -1 << endl;
        return 0;
    }
    if(cnt == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(begin(d), end(d), greater<int64_t>());
    for(int i = 0; i < n; i++){
        sum += d[i];
        if(sum >= 0){
            cout << (i + 1) + cnt << endl;
            return 0;
        }
    }
    return 0;
}