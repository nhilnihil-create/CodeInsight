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
    int N, T, A;
    cin >> N >> T >> A;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    double min_dif = 100000000;
    for(int i = 0; i < N; i++){
        min_dif = min(min_dif, abs(A - (T - H[i] * 0.006)));
    }
    for(int i = 0; i < N; i++){
        if(abs(A - (T - H[i] * 0.006)) == min_dif){
            cout << i + 1 << endl;
            return 0;
        }
    }
}
