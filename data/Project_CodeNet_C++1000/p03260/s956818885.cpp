#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b;
    
    if(a > b) {
        int arr[4];
        int B = b;
        for(int i = 0; i < a; i++) {
            arr[i] = (B++);
        }

        int x = 0;
        for(int j = 0; j < a; j++) {
            x = (a * b * arr[j]);
            if(x % 2 == 1) {
                c = arr[j];
            }
            else {
                c = 0;
            }
        }
    }
    else {
        int arr[4];
        int A = a;
        for(int i = 0; i < b; i++) {
            arr[i] = (A++);
        }
        int x = 0;
        for(int i = 0; i < b; i++) {
            x = (a * b * arr[i]);
            if(x % 2 == 1) {
                c = arr[i];
            }
            else {
                c = 0;
            }
        }
    }
    
    if(c == 0) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}