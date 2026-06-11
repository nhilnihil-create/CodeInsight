#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int X;
    cin >> X;
    int max_n = 0;
    for(int b = 1; b <= 1000; b++){
        for(int p = 2; p <= 10; p++){
            int n = pow(b, p);
            if(n <= X) max_n = max(max_n, n);
        }
    }
    cout << max_n << endl;
}
