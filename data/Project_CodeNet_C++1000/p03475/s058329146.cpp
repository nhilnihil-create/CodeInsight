#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> c(n-1);
    vector<long long> s(n-1);
    vector<long long> f(n-1);

    for(long long i = 0; i < n-1; i++) cin >> c[i] >> s[i] >> f[i];

    for(long long i = 0; i < n; i ++){
        long long t = 0;
        for(long long j = i; j < n-1; j++){
            if(t < s[j]) t = s[j];
            else if(t % f[j] == 0);
            else t = t + f[j] - t%f[j];

            t += c[j];
        }
        printf("%lld\n", t);
    }
    return 0;
}