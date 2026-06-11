#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long int;
int main() {
    ll N, Q;
    cin >> N >> Q;
    
    string S;
    cin >> S;

    vector<ll> SUM(N);
    SUM[0] = 0;
    for (size_t i = 1; i < S.size(); i++)
    {
        if (S.substr(i - 1, 2) == "AC") {
            SUM[i] = SUM[i - 1] + 1;
        } else {
            SUM[i] = SUM[i - 1];
        }
    }
    
    for (size_t i = 0; i < Q; i++)
    {
        ll l, r;
        cin >> l >> r;
        cout << (SUM[r - 1] - SUM[l - 1]) << endl;
    }
}