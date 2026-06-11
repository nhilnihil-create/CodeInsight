#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

int main() {

cin >> n;

if(n == 3) cout << 2 << " " << 5 << " " << 63 << " " ;
else {
    cout << 3 << " " << 9 << " ";
    if (n <= 15002) {
        if(n % 3 == 0) {
            int i;
            for(i = 1; i < n - 2; i++) cout << 2 * i << " ";
            cout << 2 * (i + 2) << " ";
        } else {
            for(int i = 1; i < n - 1; i++) cout << 2 * i << " ";
        }
    } else {
        if(n % 2 == 0) {
            for(int i = 1; i <= 15000; i++) cout << 2 * i << " ";
            for(int i = 1; i <= n - 15002; i++) cout << 6 * (i + 2) - 3 << " ";
        }
        else {
            for(int i = 1; i < 15000; i++) cout << 2 * i << " ";
            for(int i = 1; i <= n - 15001; i++) cout << 6 * (i + 2) - 3 << " ";
        }
    }
}

return 0;

}
