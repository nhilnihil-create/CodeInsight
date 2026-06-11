#include <iostream>
using namespace std;

long long oddsolve(long long a) { return (a+1)/2 % 2; }
long long solve(long long a) {
    if (a % 2 == 1) return oddsolve(a);
    else return oddsolve(a+1) ^ (a+1);
}
int main() {
    long long A, B; cin >> A >> B;
    cout << (solve(B) ^ solve(A-1)) << endl;
}