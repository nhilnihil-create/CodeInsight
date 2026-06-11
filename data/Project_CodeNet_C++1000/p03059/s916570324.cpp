#include <iostream>

using namespace std;

int main()
{
    int a , b , time = 0 , ans = 0;
    double t;
    cin >> a >> b >> t;
    while (time <= t + 0.5){
        if (time + a > t + 0.5){
            break;
        }
        ans += b;
        time += a;
    }
    cout << ans;
    return 0;
}
