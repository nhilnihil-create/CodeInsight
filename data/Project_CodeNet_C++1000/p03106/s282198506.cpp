#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
   if (a%b == 0) return b;
   else return gcd(b, a%b);
}

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end(), greater<long long>());
    return ret;
}


int main(){
    long long a, b, k;
    cin >> a >> b >> k;

    vector<long long> ret = divisor(gcd(a, b));

    cout << ret[k-1] << endl;
    return 0;
}