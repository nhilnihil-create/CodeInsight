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
    int A, B, K;
    cin >> A >> B >> K;
    if(B - A + 1 <= 2 * K){
        for(int i = A; i <= B; i++) cout << i << endl;
    }else{
        for(int i = A; i <= A + K - 1; i++) cout << i << endl;
        for(int i =B - K + 1; i <= B; i++) cout << i << endl; 
    }
}
