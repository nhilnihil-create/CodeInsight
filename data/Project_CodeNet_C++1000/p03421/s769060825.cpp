#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if(a * b < n || a + b > n + 1){
        cout << -1 << endl;
        return 0;
    }
    int c, e;
    for(c = 0; c < n; c++){
        if(c * a + b - c > n){
            c--;
            e = n - c * a - (b - c - 1);
            break;
        }
    }
    if(a * b == n){
        c = b;
        e = 0;
    }
    for(int i = 0; i < c; i++){
        for(int j = 0; j < a; j++) cout << n - (i + 1) * a + j + 1 << " ";
    }
    for(int j = 0; j < e; j++) cout << n - c * a - e + j + 1 << " ";
    for(int j = n - c * a - e; j > 0; j--) cout << j << " ";
    cout << endl;
}
