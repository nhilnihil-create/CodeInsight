#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL<<50;

int main(){
    int n,k;
    cin >> n >> k;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    
    long long ans = INF;
    
    for (int i = 0; i + k -1 < n; i++){
        long long cost1 = abs(x[i]) + (x[i+k-1] - x[i]);
        long long cost2 = abs(x[i+k-1]) + (x[i+k-1] - x[i]);
        
        ans = min(ans, cost1);
        ans = min(ans, cost2);
    }
    
    cout << ans << endl;
}