#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int n, cnt = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (auto x : a){
        while (x%2 == 0){
            cnt++;
            x /= 2;
        }
    }
    cout << cnt << endl;
    return 0;
}