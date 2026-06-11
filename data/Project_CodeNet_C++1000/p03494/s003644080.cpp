#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector <ll> a(n);
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    int ans=1;
    while (ans){
        for(int i = 0; i < n; i++) {
            if (a[i] % 2 == 1){
                cout << cnt;
                return 0;
            }
            a[i] = a[i] / 2;
        }
        cnt++;
        
    }

    return 0;
}