#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main(){
    int A, B;
    cin >> A >> B;
    if(A == B) cout << 2 * A << endl;
    else cout << 2 * max(A, B) -1 << endl;
}
