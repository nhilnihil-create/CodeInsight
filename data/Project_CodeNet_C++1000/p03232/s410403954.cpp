#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define INF (1ll<<60)


long long M = 1000000007;

int main(int argc, char const *argv[]) {
    long long n;cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<long long> inv(n+1),suminv(n+1);
    inv[1] = 1;
    suminv[1] = 1;
    for(int i=2;i<n+1;++i){
        inv[i] = M - (M/i)*inv[M%i];
        inv[i] %= M;
        suminv[i]=suminv[i-1]+inv[i];
        suminv[i] %= M;
    }
    long long res=0;
    for(long long i=0;i<n;++i){
        res += a[i] * suminv[i+1];
        res %= M;
        res += a[i] * suminv[n-i];
        res %= M;
        res -= a[i];
        res %= M;
    }
    for(int i=0;i<n;++i)res = (res*(i+1))%M;
    cout<<(res+M)%M<<endl;
    return 0;
}