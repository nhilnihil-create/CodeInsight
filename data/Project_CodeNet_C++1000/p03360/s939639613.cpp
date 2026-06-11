#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<long long> a(3);
    long long k;
    cin >> a[0]>> a[1] >> a[2] >> k;

    sort(a.begin(), a.end());

    long long sum = a[2];
    for(long long i = 0; i < k; i++) sum *= 2;

    sum += a[0] + a[1];

    cout << sum << endl;
    return 0;
}