#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int D; cin >> D; D = 25 - D;
    cout << "Christmas";
    rep(i, D) cout << " Eve";
    cout << endl;

    return 0;
}