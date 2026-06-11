#include<iostream>
using namespace std;

int main() {
    int a, b, k, cnt = 0;

    cin >> a >> b >> k;

    for (int i = min(a, b); i > 0; i--)  {
        if(a % i == 0 && b % i == 0) cnt++;
        if(cnt == k) {
            cout << i << endl;
            return 0;
        }
    }
}