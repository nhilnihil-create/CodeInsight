#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N = 0;
    cin >> N;
    vector<int> A(N,0);
    int E, O;
    E = 0;
    O = 0;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        E += ((1 + A.at(i))%2);
        O += (A.at(i)%2);
    }
    //cout << E << ':' << O << endl;
    cout << (ll)pow(3, N) - (ll)pow(2, E) << endl;

    return 0;
}