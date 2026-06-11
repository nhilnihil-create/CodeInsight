#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> h(n);

    for(long long i = 0; i < n; i++){
        cin >> h[i];
    }

    long long delta_min = 1e9;

    sort(h.begin(), h.end(), greater<long long>());

    for(long long i = 0; i <= n-k; i++){
        delta_min = min(h[i] - h[i+k-1], delta_min);
    }

    cout << delta_min << endl;

    return 0;

}