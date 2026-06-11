#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; 
    cin >> N;
    vector<int> v(N+2);
    ll sum = 0;
    v[0] = v[N+1] = 0;
    for (int i = 1; i <= N+1; i++)
    {
        cin >> v[i];
        sum += abs(v[i]-v[i-1]);
    }
    
    for (int i = 1; i <= N; i++)
    {
        ll ans = sum - abs(v[i]-v[i-1]) - abs(v[i+1]-v[i]) + abs(v[i+1]-v[i-1]); 
        cout << ans << '\n';
    }
        
}