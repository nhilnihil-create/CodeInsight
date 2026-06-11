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
template<typename T> 
T dig_sum(T n){
   if(n < 10)  return n;
   return dig_sum(n/10) + n%10;
}
int main(){
    int N;
    cin >> N;
    vector<ll> L(N + 1);
    L[0] = 2;
    L[1] = 1;
    for(int i = 2; i < N + 1; i++){
        L[i] = L[i - 1] + L[i - 2];
    }
    cout << L[N] << endl;
}
