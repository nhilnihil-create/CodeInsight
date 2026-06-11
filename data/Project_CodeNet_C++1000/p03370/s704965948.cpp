#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    long long weight = 0;
    long long ans = n;

    vector<long long> m(n);
    for(long long i = 0; i < n; i++){
        cin >> m[i];
        weight += m[i];
    }

    sort(m.begin(), m.end());

    ans += (x-weight)/m[0];

    cout << ans << endl;
    return 0;
}