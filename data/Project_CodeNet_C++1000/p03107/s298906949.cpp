#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int a = 0, b = 0;
    int n = S.size();
    for(int i = 0; i < n; i++) {
        if(S[i] == '0') {
            a++;
        } else {
            b++;
        }
    }
    
    cout << 2 * min(a, b);
    
    return 0;
}
