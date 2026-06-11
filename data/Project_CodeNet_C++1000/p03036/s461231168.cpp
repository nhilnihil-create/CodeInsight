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
    int r, D;
    cin >> r >> D;
    int x;
    cin >> x;
    for(int i = 0; i < 10; i++){
        x = r * x - D;
        cout << x << endl;
    }
}
