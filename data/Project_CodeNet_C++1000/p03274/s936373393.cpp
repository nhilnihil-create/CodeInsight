#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> x(n);
    for(long long i = 0; i < n; i++){
        cin >> x[i];
    }

    long long minv = abs(x[0]) + abs(x[k-1]-x[0]);
    for(long long i = 0; i + k - 1 < n; i++){
        long long minv2 = min(abs(x[i])+abs(x[i+k-1]-x[i]), abs(x[i+k-1])+abs(x[i]-x[i+k-1]));
        minv = min(minv2, minv);
    }
    cout << minv << endl;
    return 0;
}