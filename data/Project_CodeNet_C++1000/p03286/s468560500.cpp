#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    cin >> N;
    string S;
    if (N == 0) S="0";
    while (abs(N)>0) {
        if (N%2==0) S="0"+S;
        else {
            S="1"+S;
            N--;
        }
        N/=-2;
    }
    cout << S << endl;
}
