#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, B;
    cin >> A >> B;
    int a = 2 * A - 1, b = 2 * B - 1, c = A + B;
    int ans = max(a, max(b, c));
    cout << ans << endl;
}