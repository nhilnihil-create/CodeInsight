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
    int N;
    cin >> N;
    int n = 0;
    for(int num = 1; num <= N; num++){
        if(num % 2 == 0) continue;
        int count = 0;
        for(int k = 1; k <= num; k++){
            if(num % k == 0) count++;
        }
        if(count == 8) n++;
    }
    cout << n << endl;
}
