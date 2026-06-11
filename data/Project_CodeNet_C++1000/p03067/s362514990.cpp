#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, C;
    cin >> A >> B >> C;
    if ((A <= C && C <= B) || (B <= C && C <= A)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}