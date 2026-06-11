#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = b;
    if(c <= a+b+1) ans += c;
    else ans += a+b+1;
    cout << ans << endl;
    return 0;
}