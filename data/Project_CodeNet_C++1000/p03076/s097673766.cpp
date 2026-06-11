#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    vector<int> A(5);
    for(int i = 0; i < 5; i++) cin >> A[i];
    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += (A[i] + 9)/ 10 * 10;
    }
    int min_n = 100000;
    for(int i = 0; i < 5; i++){
        int m = sum - ((A[i]+9) / 10 * 10);
        m += A[i];
        min_n = min(min_n, m);
    }
    cout << min_n << endl;
}
