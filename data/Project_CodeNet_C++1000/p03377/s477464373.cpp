#include <iostream>
using namespace std;
int main() {
    int A, B, X; cin >> A >> B >> X;
    if (A > X || A + B < X) printf("%s\n", "NO");
    else printf("%s\n", "YES"); 
}