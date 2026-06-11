#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long X, Y;
    cin >> X >> Y;
    long long t = X;
    int ans = 0;
    while(t <= Y){
        ans++;
        t *= 2;
    }
    cout << ans << endl;
}