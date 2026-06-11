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
    int N;
    cin >> N;
    vector<int> V(N);
    vector<int> C(N);
    for(int i = 0; i < N; i++) cin >> V[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    ll sum = 0;
    for(int i = 0; i < N; i++){
        if(V[i] > C[i]) sum += V[i] - C[i];
    }
    cout << sum << endl;
}
