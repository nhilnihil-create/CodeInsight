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
    vector<int> P(N);
    int sum = 0;
    int max_p = 0;
    for(int i = 0; i < N; i++){
        cin >> P[i];
        sum += P[i];
        max_p = max(max_p, P[i]);
    }
    cout << sum - max_p / 2 << endl;
}
