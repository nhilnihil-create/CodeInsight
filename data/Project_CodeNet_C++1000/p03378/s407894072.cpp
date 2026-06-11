#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, m, x;
    cin >> n >> m >> x;

    vector<long long> cost(n+1, 0);

    for(long long i = 0; i < m; i++){
        long long a;
        cin >> a;
        cost[a] = 1;
    }
    long long ans = 0;
    for(long long i = x; i <= n; i++){
        ans += cost[i];
    }

    long long ans2 = 0;
    for(long long i = 0; i <= x; i++){
        ans2 += cost[i];
    }
    cout << min(ans, ans2) << endl;
    return 0;
}
