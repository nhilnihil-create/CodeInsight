#include <bits/stdc++.h>
using namespace std;

int divisor(int n){
    vector<long long> ret;
    for (int i=1; i * i <=n; i++){
        if (n % i == 0){
            ret.push_back(i);
            if (i * i != n) ret.push_back(n/i);
        }
    }
    return ret.size();
}

int main() {

    int n;
    cin >> n;
    int ans = 0;

    for(int i=1;i<=n;i+=2){
        if (divisor(i) == 8) ans += 1;
    }
    cout << ans;

    return 0;
}