#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    if((A - B) % 2){
        cout << "Borys" << "\n";
    } else {
        cout << "Alice" << "\n";
    }
    return 0;
}