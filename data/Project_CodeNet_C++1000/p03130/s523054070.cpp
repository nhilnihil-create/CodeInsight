#include <iostream>
using namespace std;

int main()
{
    int c[4] {0};
    for(int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
        c[a - 1]++;
        c[b - 1]++;
    }
    int r = 0;
    for(int i = 0; i < 4; i++) r += c[i] % 2;
    if(r == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}