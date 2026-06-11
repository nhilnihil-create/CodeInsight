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
    bool ok = false;
    for(int i = 0; i <= 25; i++){
        for(int j = 0; j <= 14; j++){
            int count = 4 * i + 7 * j;
            if(count == N) {
                ok = true;
                goto finish;
            }
        }
    }
    finish:
    if(ok) puts("Yes");
    else puts("No");
}
