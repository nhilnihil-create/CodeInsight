#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<long long> dist(n);
    for(int i = 0; i < n; i++) cin >> dist.at(i);
    long long ans =1001001001001001;
    for(int i = 0; i + k - 1 < n; i++){
        long long ABS = dist.at(i + k - 1) - dist.at(i);
        if(dist.at(i) >= 0) ans = min(ans, dist.at(i) + ABS);
        else if(dist.at(i + k - 1) <= 0) ans = min(ans, ABS - dist.at(i + k - 1));
        else ans = min(ans, ABS + min(abs(dist.at(i)), dist.at(i + k - 1)));
    }
    cout << ans << endl;

}