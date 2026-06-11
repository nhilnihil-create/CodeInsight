#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < n; ++i)
using namespace std;
const int INF = 2147483647;
using ll = long long;

int main() {
    double n,m;
    cin >> n >> m;
    double sum = 0;
    double can = pow(1/2.l,m);
    double cannot = 1 - can;
    for (int i=0;i<1e5;i++){
        sum+=(100*(n-m)+m*1900)*(i+1)*can*pow(cannot,i);
    }
    cout << sum << endl;
    return 0;
}

