#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    int a, b, t;
    int cnt = 0;
    cin >> a >> b >> t;
    for(int i = a; i <= t; i = i + a){
        cnt += b;
    }
    cout << cnt << endl;
    return 0;
}
