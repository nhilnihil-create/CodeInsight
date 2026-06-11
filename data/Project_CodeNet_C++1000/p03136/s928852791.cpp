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
    vector<int> L(N);
    for(int i = 0; i < N; i++) cin >> L[i];
    int sum = 0;
    for(int i = 0; i < N; i++) sum += L[i];
    int max_l = 0;
    for(int i = 0; i < N; i++){
        max_l = max(max_l, L[i]);
    }
    if(max_l < sum - max_l) puts("Yes");
    else puts("No");
}
