#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long X, Y;
    cin >> X >> Y;
    int cnt = 1;
    X *= 2;
    while(X <= Y){
        cnt++;
        X *= 2;
    }
    cout << cnt << '\n';
    return 0;
}