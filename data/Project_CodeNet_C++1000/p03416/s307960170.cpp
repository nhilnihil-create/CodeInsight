#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b; i++){
        int ii = i;
        int i1 = ii % 10;
        ii /= 10;
        int i2 = ii % 10;
        ii /= 100;
        if(ii % 10 != i2) continue;
        ii /= 10;
        if(ii % 10 == i1) ans++;
    }
    cout << ans << endl;
    return 0;
}