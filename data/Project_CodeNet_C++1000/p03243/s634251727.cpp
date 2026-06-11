#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 111;
    while(ans < n) ans += 111;
    cout << ans << endl;
    return 0;
}