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
    int N, K;
    cin >> N >> K;
    int num = 1;
    for(int i = 0; i < N; i++){
        if(num * 2 >= num + K) num += K;
        else num *= 2;
    }
    cout << num << endl;
}
